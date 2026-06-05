class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            int z=target-nums[i];
            if(mp.count(z)){
                res.push_back(mp[z]);
                res.push_back(i);
            }
            mp[nums[i]]=i;
        }
        return res;
    }
};
