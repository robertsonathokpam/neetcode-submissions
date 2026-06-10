class Solution {
public:
vector<vector<int>>z;
    void fn(int i,vector<int>res,vector<int>&nums){
        if(i==nums.size()){
            z.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        fn(i+1,res,nums);
        res.pop_back();
        fn(i+1,res,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       int n=nums.size();
       z.clear();
       vector<int>res;
       fn(0,res,nums);
       return z;
    }
};
