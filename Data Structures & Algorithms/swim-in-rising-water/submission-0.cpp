class Solution {
public:
    int n=0;

    bool fn(int mid,vector<vector<int>>& grid) {
        
        vector<vector<int>> dist(n, vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({0, 0});
        dist[0][0] = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r == n - 1 && c == n - 1)
                return true;

            int dr[4] = {-1, 1, 0, 0};
            int dc[4] = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++) {
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !dist[nr][nc]) {
                    if (grid[nr][nc] <= mid) {
                        dist[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
         n = grid.size();
        //queue < tuple < int, int, int >>> pq;
        int s = grid[0][0], e = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                e = max(e, grid[i][j]);
            }
        }
        int res=0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (fn(mid,grid)) {
                res=mid;
                e=mid-1;
            }else s=mid+1;
        }
        return res;
    }
};