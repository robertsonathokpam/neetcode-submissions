class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>>row,col;
        map<pair<int,int>,unordered_set<char>>sq;
       
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    pair<int,int>ind={i/3,j/3};
                    if(row[i].count(board[i][j]) || col[j].count(board[i][j]) || sq[ind].count(board[i][j])){
                        return false; 
                    }
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    sq[ind].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
