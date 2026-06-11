class Solution {
   public:
    vector<vector<int>> ans;
    void fn(int ind, vector<int>& nums, int sum, vector<int> res) {
        int n = nums.size();
        if (sum == 0) {
            ans.push_back(res);
            return;
        }
        if (sum < 0 || ind == n) return;
        for (int j = ind; j < n; j++) {
            if (j > ind && nums[j] == nums[j - 1]) continue;
            res.push_back(nums[j]);
            fn(j + 1, nums, sum - nums[j], res);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int sum) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        fn(0, nums, sum, res);
        return ans;
    }
};
