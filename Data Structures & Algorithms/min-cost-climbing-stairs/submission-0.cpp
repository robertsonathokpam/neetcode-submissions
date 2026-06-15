class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
       vector<int>dp(n+1,0); 
       for(int i=1;i<=n;i++){
          int x=0,y=0;
          if(i-1>=0) x=dp[i-1]+cost[i-1];
          if(i-2>=0) y=dp[i-2]+cost[i-2];
          dp[i]=min(x,y);
       }  
       return dp[n];
    }
};
