class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>ind(n+1,0);
        for(int i=0;i<trust.size();i++){
            ind[trust[i][1]]++;
            ind[trust[i][0]]--;
        }
        int res=-1;
        for(int i=1;i<=n;i++){
          if(ind[i]==n-1){
              res=i;
          }
        }
        return res;
    }
};