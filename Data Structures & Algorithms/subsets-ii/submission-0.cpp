class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0;i<(1<<n);i++){
           vector<int>res;
           for(int j=0;j<n;j++){
               if(((1<<j)&i) !=0){  
                 res.push_back(nums[j]);
               }
           }
           st.insert(res);
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
