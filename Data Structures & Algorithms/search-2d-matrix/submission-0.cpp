class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int u=0,d=n-1;
        while(u<=d){
            int m1=(u+d)>>1;
            if(matrix[m1][0]<=target && target<=matrix[m1][m-1]){
                int l=0,r=m-1;
                while(l<=r){
                    int m2=(l+r)>>1;
                    if(matrix[m1][m2]==target){
                        return true;
                    }else if(matrix[m1][m2]>target){
                       r=m2-1;
                    }else{
                       l=m2+1;
                    }
                }
                return false;
            }else if(matrix[m1][0]>target){
                d=m1-1;
            }else if(matrix[m1][m-1]<target){
                u=m1+1;
            }else return false;
        }
        return false;
    }
};
