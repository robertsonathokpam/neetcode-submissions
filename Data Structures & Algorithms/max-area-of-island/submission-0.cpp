class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0,res=0;
        int dx[4]={0,-1,1,0};
        int dy[4]={1,0,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(!vis[i][j] && grid[i][j]==1){
                cnt=1;
                 q.push({i,j});
                 vis[i][j]=1;
                 while(!q.empty()){
                    auto [x,y]=q.front();
                    q.pop();
                    for(int a=0;a<4;a++){
                            int nx=x+dx[a];
                            int ny=y+dy[a];
                            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                                cnt++;
                                vis[nx][ny]=1;
                                q.push({nx,ny});
                            }
                        }
                 }
                 res=max(res,cnt);
               }
            }
        }
        return res;
    }
};
