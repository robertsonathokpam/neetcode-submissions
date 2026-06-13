class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),[](auto& x,auto &y ){
            if(y[1]==x[1]){
                return x[0]<y[0];
            }
            return x[1]<y[1];
        });
        
        int res=0;
        int prev=nums[0][1];
        for(int i=1;i<nums.size();i++){
            if(nums[i][0]<prev){
                res++;
            }else{
               prev=nums[i][1];
            }
        }

        return res;
    }
};
