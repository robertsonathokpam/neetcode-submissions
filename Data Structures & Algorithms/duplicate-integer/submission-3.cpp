class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(int num:nums){
            if(st.count(num)) return 1;
            st.insert(num);
        }
        return 0;
    }
};