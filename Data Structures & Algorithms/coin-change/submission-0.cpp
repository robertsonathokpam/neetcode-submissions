class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int m=amount;
        vector<vector<int>>dp(n+1,vector<int>(m+1,1e5));
        dp[0][0]=0;
        for(int j=0;j<=m;j++){
            for(int i=1;i<=n;i++){
                dp[i][j]=dp[i-1][j];
                if(j-coins[i-1]>=0){
                    dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i-1]]);
                }
            }
        }
        if(dp[n][m]==1e5){
            return -1;
        }
        return dp[n][m];
    }
};
