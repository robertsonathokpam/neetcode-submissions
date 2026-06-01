class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        vector<int>arr;
        for(int i=0;i<nums.size();i++){
            int res=target-nums[i];
            if(mp.count(res)){
                arr.push_back(mp[res]+1);
                arr.push_back(i+1);
                break;
            }
            mp[nums[i]]=i;
        }
        return arr;
    }
};
