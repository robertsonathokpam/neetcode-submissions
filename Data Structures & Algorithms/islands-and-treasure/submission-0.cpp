class Solution {
   public:
    const int inf = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        int dx[4] = {0, -1, 1, 0};
        int dy[4] = {1, 0, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int a = 0; a < 4; a++) {
                int nx = x + dx[a];
                int ny = y + dy[a];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == inf) {
                    q.push({nx, ny});
                    grid[nx][ny] = 1 + grid[x][y];
                }
            }
        }
    }
};
