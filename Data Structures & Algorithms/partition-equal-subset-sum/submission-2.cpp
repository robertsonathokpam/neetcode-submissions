class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums) sum+=num;
        if(sum&1){
            return false;
        }
        int n=nums.size();
        //vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        vector<int>dp(sum+1,0);
        //for(int i=0;i<n;i++) dp[i][0]=1;
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=sum/2;j>=nums[i];j--){
                  dp[j]= dp[j-nums[i]] || dp[j];           
            }
        }
        return dp[sum/2];
    }
};
