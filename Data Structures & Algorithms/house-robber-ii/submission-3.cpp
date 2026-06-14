class Solution {
public:
    
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return nums[0];
        int curr=0;
        int prev1=0,prev2=0;
        int res1=0,res=0; 
        for(int i=0;i<n-1;i++){
           res=prev1;
           curr=nums[i]+prev2;
           res=max(res,curr);
           prev2=prev1;
           prev1=res;
        }
        prev1=0;
        prev2=0;
        curr=0;
        for(int i=1;i<n;i++){
           res1=prev1;
           curr=nums[i]+prev2;
           res1=max(res1,curr);
           prev2=prev1;
           prev1=res1;
        }
        return max(res,res1);
    }
};
