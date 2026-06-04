class Solution {
public:
    int n;
    int cnt=0;
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
    int findTargetSumWays(vector<int>& nums, int t) {
        n=nums.size();
        cnt=0;
        fn(0,nums,t);
        return cnt;
    }
};
