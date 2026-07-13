class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=0,mini_sum=0,maxi_sum=0,mini=nums[0],maxi=nums[0];
        for(int i=0;i<n;i++){
            mini_sum=min(nums[i],mini_sum+nums[i]);
            mini=min(mini,mini_sum);
            maxi_sum=max(nums[i],maxi_sum+nums[i]);
            maxi=max(maxi,maxi_sum);
            sum+=nums[i];
        }
        if(maxi_sum<0){
            return maxi;
        }else return max(maxi,sum-mini);
    }
};