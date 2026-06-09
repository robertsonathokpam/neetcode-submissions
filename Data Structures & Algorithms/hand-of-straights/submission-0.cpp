class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int g) {
        map<int,int>mp;
        int maxi=0;
        for(int num:nums){
            mp[num]++;
        }

        int n=nums.size();
        if(n%g!=0) return false;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(mp[nums[i]]>0){
                for(int j=nums[i];j<nums[i]+g;j++){
                    if(mp[j]==0) return false;
                    mp[j]--;
                }
            }
        }
        return true;
    }
};
