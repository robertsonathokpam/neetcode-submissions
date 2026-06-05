class Solution {
public:
    int n;
    int cnt=0;
    /*
    void fn(int i,vector<int>&nums, int t){
        if(i==n){
            if(t==0){
                cnt++;
            }
            return;
        }
        fn(i+1,nums,t-nums[i]);
        fn(i+1,nums,t+nums[i]);
    }
    */
    int findTargetSumWays(vector<int>& nums, int t) {
        n=nums.size();
        cnt=0;
        //fn(0,nums,t);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        sum=(sum+t);
        if(sum%2!=0){
            return 0;
        }
        sum/=2;
        vector<int>dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=0;j--){
               if(j-nums[i]>=0){
                 dp[j]+=dp[j-nums[i]];
               }
            }
        }
        return dp[sum];
    }
};
