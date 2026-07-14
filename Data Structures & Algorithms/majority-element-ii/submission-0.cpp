class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int cnt=floor(n/3);
        for(int i=0;i<n;i++){
           mp[nums[i]]++;
        }
        vector<int>res;
        for(auto it:mp){
           if(it.second>cnt){
              res.push_back(it.first);
           }
        }
        sort(res.begin(),res.end());
        return res; 
    }
};