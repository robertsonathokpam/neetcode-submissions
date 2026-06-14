class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int curr=0,prev1=0,prev2=0;
        for(int i=0;i<n;i++){
            curr=prev1;
            curr=max(curr,nums[i]+prev2);
            
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};
