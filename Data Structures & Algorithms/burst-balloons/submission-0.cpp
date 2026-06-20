//burst ballon
class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int fn(int l,int r,vector<int>&nums){
        if (l > r) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];
        
        int res=0;
        for(int i=l;i<=r;i++){
            res=max(res,(nums[l-1]*nums[i]*nums[r+1])+fn(l,i-1,nums)+fn(i+1,r,nums));
        }
        return dp[l][r]=res;
    }
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        n=nums.size();
        dp.assign(n+2,vector<int>(n+2,-1));
        return fn(1,n-2,nums);
    }
};
