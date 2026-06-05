class Solution {
public:
    int orangesRotting(vector<vector<int>>& b) {
        int n=b.size();
        int m=b[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(b[i][j]==2){
                   vis[i][j]=1;
                   q.push({i,j,0});
               }
            }
        }
       int res=0;
        while(!q.empty()){
            auto [r,c,cnt]=q.front();
            q.pop();
            vector<int>dr={-1,0,1,0};
            vector<int>dc={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && b[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    int cnt1=cnt+1;
                    res=max(res,cnt1);
                    q.push({nr,nc,cnt1});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return res;
    }
};
