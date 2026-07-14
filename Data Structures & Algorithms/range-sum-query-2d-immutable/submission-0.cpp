class NumMatrix {
public:
    vector<vector<int>>pref;
    int n,m;
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size(),m=matrix[0].size();
        pref.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=matrix[i][j];
                if(i-1>=0){
                    sum+=pref[i-1][j];
                }
                if(j-1>=0){
                    sum+=pref[i][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    sum-=pref[i-1][j-1];
                }
                pref[i][j]=sum;
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
            int sum=pref[r2][c2];
            if(r1-1>=0){
                sum-=pref[r1-1][c2];
            }
            if(c1-1>=0){
                sum-=pref[r2][c1-1];
            }
            if(r1-1>=0 && c1-1>=0){
                sum+=pref[r1-1][c1-1];
            }
            return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */