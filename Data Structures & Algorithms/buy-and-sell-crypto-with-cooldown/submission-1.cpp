class Solution {
public:
    vector<vector<int>>dp;
    int n;

    int fn(int ind,vector<int>&prices,int buy){
        
        int n=prices.size();
        
        if(ind>=n){
           return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int skip= fn(ind+1,prices,buy);
        int profit=skip;
        if(buy==1){
           int take = -prices[ind]+fn(ind+1,prices,0);
           profit=max(profit,take);
        }else{
            int sell=prices[ind]+fn(ind+2,prices,1);
            profit=max(profit,sell);
        }
        
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
       n=prices.size();
       dp.assign(n+1,vector<int>(2,0));
       //return fn(0,prices,1);

       for(int i=n-1;i>=0;i--){
        for(int j=1;j>=0;j--){
            int skip=dp[i+1][j];
            int profit=skip;
            int take=0,sell=0;
            if(j==1) {
                take=-prices[i]+dp[i+1][0];
                profit=max(profit,take);
            }else {
               sell=prices[i];
               if(i+2<n) sell+=dp[i+2][1];
                profit=max(profit,sell);
            }
            dp[i][j]=profit;
        }
       }

       return dp[0][1];    
    }
};