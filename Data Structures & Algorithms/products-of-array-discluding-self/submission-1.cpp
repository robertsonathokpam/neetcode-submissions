class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n=nums.size();
       vector<int>pref(n,0),suff(n,0);
       pref[0]=nums[0];
       for(int i=1;i<n;i++) pref[i]=pref[i-1]*nums[i];
       suff[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--) suff[i]=suff[i+1]*nums[i];
       vector<int>res(n);
       res[0]=suff[1];
       res[n-1]=pref[n-2];
       for(int i=1;i+1<n;i++){
         res[i]=pref[i-1]*suff[i+1];
       }
       return res;
    }
};
