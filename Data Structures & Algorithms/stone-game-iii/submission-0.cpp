//leetcode 1406
class Solution {
public:
    int n;
    vector<int>dp;
    vector<int>nums;

    int fn(int i){
        if(i>=n) return 0;
        if(dp[i]!= -1e7) return dp[i];
        int curr=0;

        int t1=-1e7;
        t1=max(t1,nums[i]-fn(i+1));

        if(i+1<n) t1=max(t1,nums[i]+nums[i+1]-fn(i+2));
        
        if(i+2<n) t1=max(t1,nums[i]+nums[i+1]+nums[i+2]-fn(i+3));

        return dp[i]=t1;
    }
    string stoneGameIII(vector<int>&arr) {
        nums=arr;
        n=nums.size();
        int sum=0;
        for(int num:nums) sum+=num;
        dp.assign(n+4,-1e7);
        int k=fn(0);
        /*
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int take=0,notake=0,curr=0;
            for(int j=i;j<i+3;j++){
              take=nums[j]+dp[j+3];
              notake=dp[j+3];
              curr=max(curr,max(take,notake));
            }
            dp[i]=curr;
        }
        int k=dp[0];
        */
        if(k>0){
            return "Alice";
        }else if(k<0){
            return "Bob";
        }else return "Tie";
    }
};