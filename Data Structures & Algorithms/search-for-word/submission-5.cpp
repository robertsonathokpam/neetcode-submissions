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
       if(r>=n || c>=m || r<0 || c<0) return false;
       if(vis[r][c]) return false;
       if(b[r][c]!=s[ind]) return false;
       
       vector<int>dc={-1,0,1,0};
       vector<int>dr={0,-1,0,1};
       bool k=false;
       vis[r][c]=1;
       for(int i=0;i<4;i++){
          int nr=r+dr[i];
          int nc=c+dc[i];
          if(dfs(nr,nc,ind+1)) return true;
       }
       vis[r][c]=0;
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
            if(dfs(i,j,0)) return true;
         }
        }
        return false;
    }
};
