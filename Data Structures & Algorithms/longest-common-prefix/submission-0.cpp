class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        map<string,int>mp;
        int n=s.size();
        string r;
        for(int i=0;i<n;i++){
             r="";
            for(int j=0;j<s[i].size();j++){
                r+=s[i][j];
                mp[r]++;
            }
        }
        int len=0;
        string res="";
        for(auto it:mp){
            if(it.second>=n){
                if(len<it.first.size()){
                    len=it.first.size();
                    res=it.first;
                }
            }
        }

        return res;
    }
};