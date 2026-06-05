class Solution {
public:
    void solve(vector<vector<char>>& b) {
        int n=b.size();
        int m=b[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(b[i][j]=='O' && (i==0 || j==0 || j==m-1 || i==n-1)){
                   vis[i][j]=1;
                   q.push({i,j});
               }
            }
        }
       
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            vector<int>dr={-1,0,1,0};
            vector<int>dc={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && b[nr][nc]=='O' && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]=='O' && !vis[i][j]){
                    b[i][j]='X';
                }
            }
        }

    }
};
