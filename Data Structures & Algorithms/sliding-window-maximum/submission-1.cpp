class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxi = 0;
        map<int, int> mp;
        vector<int> res;

        int n = nums.size();

        for (int i = 0; i < min(n, k); i++) {
            mp[nums[i]]++;
        }
    
        auto it=mp.rbegin();
        res.push_back(it->first);
        int r = k;
        int l=0;
        while (r < n) {
            mp[nums[r]]++;
            r++;
            mp[nums[l]]--;
            if (mp[nums[l]] == 0) {
                mp.erase(nums[l]);
            }
            l++;
            it=mp.rbegin();
            res.push_back(it->first);
        }
        return res;
    }
};
