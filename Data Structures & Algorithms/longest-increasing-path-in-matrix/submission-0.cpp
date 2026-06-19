class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    
    int dfs(int r,int c,vector<vector<int>>& matrix){
            int len=1;
            if(dp[r][c]!=-1) return dp[r][c];
            vector<int>dc={-1,1,0,0};
            vector<int>dr={0,0,-1,1};
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nc>=0 && nr>=0 && nr<n && nc<m && matrix[nr][nc]>matrix[r][c]){
                      len=max(len,1+dfs(nr,nc,matrix));
                }
            }
            return dp[r][c]=len;
        }
        
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int len=1;
        dp.assign(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   len=max(len,dfs(i,j,matrix));
            }
        }
         return len;
    }
};
