class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            if(i-1>=0){
                dp[i]=dp[i-1];
            }
            int curr=nums[i];
            if(i-2>=0) curr+=dp[i-2];
            dp[i]=max(dp[i],curr);
        }
        return dp[n-1];
    }
};
