class Solution {
public:
    int n,m;
    
    bool fn(int lim,vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>dr={-1,1,0,0};
        vector<int>dc={0,0,-1,1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0]=1;
        while(!q.empty()){
            auto [r,c]=q.front();
            if(r==n-1 && c==m-1) return true;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc]){
                    if(abs(grid[nr][nc]-grid[r][c])<=lim){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size(); 
        m=heights[0].size();

        int s=0,e=0;
        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++) e=max(e,heights[i][j]);
        
        int res=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(fn(mid,heights)){
                res=mid;
                e=mid-1;
            }else s=mid+1;
        }
        return res;
    }
};