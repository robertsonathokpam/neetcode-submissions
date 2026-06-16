class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums) sum+=num;
        if(sum&1){
            return false;
        }
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        
        for(int i=0;i<n;i++) dp[i][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                 if(j-nums[i-1]>=0) dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                 else dp[i][j]=dp[i-1][j];           
            }
        }
        return dp[n][sum/2];
    }
};
