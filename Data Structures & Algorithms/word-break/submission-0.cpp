class Solution {
public:
    unordered_map<string,int>mp;
    vector<int>dp;
    int n;

    int fn(int ind, string& s){
        if(ind==n){
            return 1; 
        }

        if(dp[ind]!=-1) return dp[ind];

        int k=0;
        for(int i=ind;i<n;i++){
            string x=s.substr(ind,i-ind+1);
            if(mp.count(x)){
                k|=fn(i+1,s);
            }
        }

        return dp[ind]=k; 
    }

    bool wordBreak(string s, vector<string>& w) {
         n=s.size();
         for(string s:w) mp[s]++;
         dp.assign(n,-1);
         return fn(0,s); 
    }
};
