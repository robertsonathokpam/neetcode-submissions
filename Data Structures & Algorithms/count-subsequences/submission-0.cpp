class Solution {
public:

   vector<vector<int>>dp;
    int fn(int i1,int i2,string& s, string& t){
        
        if(i2==t.size()){
            return 1;
        }

        if(i1>=s.size()) return 0;

        if(dp[i1][i2]!=-1) return dp[i1][i2];
        int cnt=0;
        cnt+=fn(i1+1,i2,s,t); 

        if(s[i1]==t[i2]){
            cnt+=fn(i1+1,i2+1,s,t);
        }
      // return cnt;
       return dp[i1][i2]=max(dp[i1][i2],cnt);
    }
    int numDistinct(string s, string t) {
       dp.assign(s.size()+1,vector<int>(t.size(),-1));
       return fn(0,0,s,t);
    }
};