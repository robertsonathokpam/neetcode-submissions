class Solution {
public:
    string s1,s2,s3;
    int n,m,sz;
    vector<vector<int>>dp;
    int fn(int i,int j,int k){
       if(k==sz){
          return 1; 
       }
       if(dp[i][j]!=-1) return dp[i][j];
       bool res=0;
       if(i<n && s1[i]==s3[k]){
          res|=fn(i+1,j,k+1);
       }
        if(j<m && s2[j]==s3[k]){
          res|=fn(i,j+1,k+1);
       }

       return dp[i][j]=res;
    }
    bool isInterleave(string str1, string str2, string str3) {
        s1=str1;
        s2=str2;
        s3=str3;

        n=s1.size();
        m=s2.size();
        sz=s3.size();
        if(n+m!=sz) return false;
        dp.assign(n+1,vector<int>(m+1,-1));
        int k= fn(0,0,0);
        if(k==-1) return false;
        return k;
    }
};
