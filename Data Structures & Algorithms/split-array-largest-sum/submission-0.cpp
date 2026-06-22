class Solution {
public:
    
    bool fn(int mid,vector<int>& nums, int k){
        int sum=0;
        int cnt=1;
        for(int i=0;i<nums.size();i++){
            //sum+=nums[i];
            if(sum+nums[i]>mid){
                sum=nums[i];
                cnt++;
            }else sum+=nums[i];

        }
        return cnt<=k;
    }

    int splitArray(vector<int>& nums, int k) {
       int s=0,e=0;
       int n=nums.size();
       for(int i=0;i<n;i++) {
        e+=nums[i];
        s=max(s,nums[i]);
       }
       int sum=e;
       int res=0;
       while(s<=e){
         int mid=s+(e-s)/2;
         if(fn(mid,nums,k)){
             res=mid;
             e=mid-1;
         }else s=mid+1;
       }

       return res;
    }
};