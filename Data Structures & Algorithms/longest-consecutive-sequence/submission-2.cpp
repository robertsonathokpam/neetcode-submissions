class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int n=nums.size();
        if(nums.size()==0) return 0;
        int res=1;
        int cnt=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
           if(mp.count(nums[i]-1)){
             mp[nums[i]]=1+mp[nums[i-1]];
             res=max(res,mp[nums[i]]);
           }else  mp[nums[i]]++;
        }
        return res;
    }
};
