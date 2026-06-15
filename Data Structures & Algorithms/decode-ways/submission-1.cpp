class Solution {
public:
    unordered_map<string,int>mp;
    int n=0;
    vector<int>dp;

    int fn(int ind, string &s){
        
        if(ind==n){
            return 1;
        }
        if(dp[ind]!=-1) return dp[ind]; 

        int cnt=0;
        for(int i=ind;i<n;i++){
            string x=s.substr(ind,i-ind+1);
            if(mp.count(x)){
               cnt+=fn(i+1,s);
            }
        }

        return dp[ind]=cnt;
    }

    int numDecodings(string s) {
        mp.reserve(26);
        n=s.size();
        dp.assign(n+1,-1);
        for(int i=1;i<=26;i++) mp[to_string(i)]++;
        return fn(0,s);
    }
};
