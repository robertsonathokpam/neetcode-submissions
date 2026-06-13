class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        res.push_back({nums[0][0],nums[0][1]});
        int n=nums.size();
        for(int i=1;i<n;i++){
            auto& it=res.back();
            if(nums[i][0]<=it[1]){
                it[1]=max(it[1],nums[i][1]);
                it[0]=min(it[0],nums[i][0]);
            }else res.push_back({nums[i][0],nums[i][1]});
        }
        return res;
    }
};
