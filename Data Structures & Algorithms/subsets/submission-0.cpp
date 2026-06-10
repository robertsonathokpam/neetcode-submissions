class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>>z;
       for(int i=0;i<(1<<n);i++){
        vector<int>res;
          for(int j=0;j<n;j++){
             if((1<<j) & i){
                 res.push_back(nums[j]);
             }
          }
          z.push_back(res);
       }   
       return z;
    }
};
