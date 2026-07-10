class Solution {
public:
    vector<int>dp;
    int fn(int n){

        if(n==0){
           return 0;
        }else if(n<0) return 1e5;

        if(dp[n]!=-1) return dp[n];
        int cnt=1e5;
        for(int i=1;i*i<=n;i++){
            cnt=min(cnt,1+fn(n-i*i));
        }
        return dp[n]=cnt;
    }
    int numSquares(int n) {
        dp.assign(n+1,-1);
        return fn(n);
    }
};