class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_set<int>st(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=nums[n-1];
        if(maxi<=0) return 1;
        for(int i=1;i<=maxi;i++){
            if(!st.count(i)){
                return i;
            }
        }
        return  maxi+1;
    }
};