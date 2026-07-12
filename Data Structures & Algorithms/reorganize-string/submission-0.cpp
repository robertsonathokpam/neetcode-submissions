class Solution {
public:
    string reorganizeString(string s) {
        
        vector<int>arr(26,0);
        for(int i=0;i<s.size();i++){
           arr[s[i]-'a']++;
        }
        
        priority_queue<pair<int,char>>pq;

        for(int i=0;i<26;i++){
            if(arr[i]>0){
                pq.push({arr[i],'a'+ i });
            }
        }

        string res="";

        while(!pq.empty()){
            auto [cnt1,c1]=pq.top();
            pq.pop();
            int n=res.size();
            if(n>=1 && res[n-1]==c1){
                if(pq.size()==0) break;
                
                auto [cnt2,c2]=pq.top();
                pq.pop();

                res+=c2;
                cnt2--;
                if(cnt2) pq.push({cnt2,c2});
                pq.push({cnt1,c1});
            }else{
                res+=c1;
                cnt1--;
                if(cnt1) pq.push({cnt1,c1});
            }
        }
        //return res;
       if(res.size()==s.size()){
            return res;
        }
        return "";
        
    }
};