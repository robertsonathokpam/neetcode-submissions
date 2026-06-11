class Solution {
public:
    vector<vector<int>>ans;
    void fn(int ind,vector<int>& nums, int target,vector<int>res){
        if(target<0 || ind==nums.size()) return;
        if(target==0){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[ind]);
        fn(ind,nums,target-nums[ind],res);
        res.pop_back();
        fn(ind+1,nums,target,res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
         vector<int>res;
         fn(0,nums,target,res);
         return ans;
    }
};
