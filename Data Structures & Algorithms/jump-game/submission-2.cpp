class Solution {
public:
    bool canJump(vector<int>& nums) {
      int range=0;
      int n=nums.size();
      vector<int>flag(n,0);
      for(int i=0;i<n;i++){
         if(i<=range){
             flag[i]=1;
            if(nums[i]>0) range=max(range,nums[i]+i);
         }
      }
      return flag[n-1]==1; 
    }
};
