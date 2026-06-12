class Solution {
public:
    vector<vector<int>>ans;
    void fn(int ind,vector<int>&nums){
        if(ind==nums.size()){
           ans.push_back(nums);
           return;
        }

        for(int j=ind;j<nums.size();j++){
            swap(nums[ind],nums[j]);
            fn(ind+1,nums);
            swap(nums[ind],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        fn(0,nums);
        return ans;
    }
};
