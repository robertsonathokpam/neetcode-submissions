class Solution {
public:
    vector<vector<char>>b;
    string s;
    int n,m;
    vector<vector<int>>vis;
    bool dfs(int r,int c,int ind){
      
       if(ind==s.size()){
          return true;
       }
       vector<int>dc={-1,0,1,0};
       vector<int>dr={0,-1,0,1};

       for(int i=0;i<4;i++){
          int nr=r+dr[i];
          int nc=c+dc[i];
          if(nr<n && nc<m && nr>=0 && nc>=0 && !vis[nr][nc]){
            if(b[nr][nc]==s[ind]){
                vis[nr][nc]=1;
               if(dfs(nr,nc,ind+1)) return true;
               vis[nr][nc]=0;
               //to revisit the path to explore other possible new paths  
             } 
          }
       }

       return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        b=board;
        n=b.size();
        m=b[0].size();
        vis.assign(n,vector<int>(m,0));
        s=word;
        for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            if(b[i][j]==s[0]){
              vis[i][j]=1;
              if(dfs(i,j,1)) return true;
              vis[i][j]=0;
            }
         }
        }
        return false;
    }
};
