class Solution {
public:
    vector<int>dp;
    int fn(int x){
        if(x==0){
           return 1;
        }
        if(dp[x]!=-1) return dp[x];
        int rem=-1e5;
        for(int i=1;i<x;i++){
            int curr=i*(x-i);
            rem=max(rem,i*fn(x-i));
            rem=max(rem,curr);
        }
        dp[x]=rem;
        return dp[x];
    }
    int integerBreak(int n) {
        dp.assign(60,-1);
        //if(n==3) return 2;
        return fn(n);
    }
};