class Solution {
   public:
    int n, m;
    vector<vector<int>> vis1, vis2;
    vector<int> dc = {-1, 0, 1, 0};
    vector<int> dr = {0, -1, 0, 1};
    vector<vector<int>> res;

    void dfs(int r, int c, vector<vector<int>>& h, vector<vector<int>>& vis) {
         vis[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + r;
            int nc = dc[i] + c;
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]) {
                if (h[nr][nc] >= h[r][c]) {
                    dfs(nr, nc, h, vis);
                }
            }
        }
    }    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        n = h.size(), m = h[0].size();
        vis1.assign(n, vector<int>(m, 0));
        vis2.assign(n, vector<int>(m, 0));
       
        for (int j = 0; j < m; j++) {
            if (!vis1[0][j]) dfs(0, j, h, vis1);
        }
        for (int i = 0; i < n; i++) {
            if (!vis1[i][0]) dfs(i, 0, h, vis1);
        }
        for (int j = 0; j < m; j++) {
            if (!vis2[n - 1][j]) dfs(n - 1, j, h, vis2);
        }
        for (int i = 0; i < n; i++) {
            if (!vis2[i][m - 1]) dfs(i, m - 1, h, vis2);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j] && vis2[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
