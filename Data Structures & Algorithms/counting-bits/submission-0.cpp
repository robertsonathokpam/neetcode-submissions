class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>nums(n+1);
        int cnt=0;
        for(int i=0;i<=n;i++){
            int z=i;
            cnt=0;
            for(int j=0;j<10;j++){
                if((1<<j)&z){
                    cnt++;
                }
            }
            nums[i]=cnt;;
        }
        return nums;
    }
};
