class Solution {
public:
    int n;
    vector<vector<vector<char>>> ans;

    bool valid(int& r, int& c, vector<int>& row, vector<int>& col,
               vector<vector<char>>& res) {
        if (row[r] || col[c])
            return false;
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (i >= 0 && j >= 0 && res[i][j] == 'Q')
                return false;
        }
        for (int i = r + 1, j = c + 1; i <= n - 1 && j <= n - 1; i++, j++) {
            if (i < n && j < n && res[i][j] == 'Q')
                return false;
        }
        for (int i = r + 1, j = c - 1; i <= n - 1 && j >= 0; i++, j--) {
            if (i < n && j < n && res[i][j] == 'Q')
                return false;
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j <= n - 1; i--, j++) {
            if (i < n && j < n && res[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void fn(int r, vector<vector<char>>& res, vector<int>& row,
            vector<int>& col) {

        if (r == n) {
            ans.push_back(res);
            return;
        }
        // if(r<0 || c<0 ||r>=n ||c>=n ||!valid(r,c,row,col,res)) return;
        // if(r>=0 && c>=0 && r<n && c<n && valid(r,c,row,col,res)) return;

        for (int i = 0; i < n; i++) {
            if (r >= 0 && i >= 0 && r < n && i < n &&
                valid(r, i, row, col, res)) {
                row[r] = 1;
                col[i] = 1;
                res[r][i] = 'Q';
                fn(r + 1, res, row, col);
                col[i] = 0;
                res[r][i] = '.';
                row[r]=0;
            }
        }
        row[r] = 0;
    }
    vector<vector<string>> solveNQueens(int N) {
        n = N;
        vector<vector<char>> res(n, vector<char>(n, '.'));
        vector<int> row(n, 0);
        vector<int> col(n, 0);

        fn(0, res, row, col);

        vector<vector<string>> final;
        for (int i = 0; i < ans.size(); i++) {
            vector<string> z;
            for (int j = 0; j < n; j++) {
                string s;
                s.resize(n);
                for (int k = 0; k < n; k++) {
                    s[k] = ans[i][j][k];
                }
                z.push_back(s);
            }
            final.push_back(z);
        }

        return final;
    }
};