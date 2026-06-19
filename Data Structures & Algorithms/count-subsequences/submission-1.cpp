class Solution {
public:
   vector<vector<unsigned long long>>dp;
    int numDistinct(string s, string t) {
       int n=s.size();
       int m=t.size();
       dp.assign(n+2,vector<unsigned long long>(m+2,0));

       for(int i=0;i<=n;i++) dp[i][m]=1;

       for(int i=n-1;i>=0;i--){
         for(int j=m-1;j>=0;j--){
           unsigned long long cnt=dp[i+1][j];
            if(s[i]==t[j]){
                cnt+=dp[i+1][j+1];
            }
            dp[i][j]=cnt;
         }
       }

       return (int)dp[0][0];
       //return fn(0,0,s,t);
    }
};