class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            int curr=1;
            for(int j=i;j<n;j++){
                curr=curr*nums[j];
                if(curr==0) break;
                res=max(res,curr);
            }
        }
        return res;
    }
};
