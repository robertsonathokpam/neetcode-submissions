class Solution {
   public:
    string longestPalindrome(string s1) {
        int n = s1.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        int len = 0;
        int l=-1,r=-1;
        int res=0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = i ; j < n; j++) {
                if ((s1[i] == s1[j]) && (j-i<=2 || dp[i+1][j-1]) ) {
                    dp[i][j]=1;
                    if(res<j-i+1){
                        res=j-i+1;
                        l=i;
                    }
                }
            }
        }
        string y=""; 
       for(int i=l;i<res+l;i++){
           y+=s1[i];
       }
       return y;
    }
};
