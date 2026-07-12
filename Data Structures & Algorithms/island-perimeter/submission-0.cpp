class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    grid[i][j]=2;
                    q.push({i, j});
                    break;
                }
            }
        }

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        int sum = 0, cnt = 0;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            cnt = 4;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    if (grid[nr][nc]==1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        cnt--;
                    }else if(grid[nr][nc]==2){
                        cnt--;
                    }
                }
            }
            sum += cnt;
        }
        return sum;
    }
};