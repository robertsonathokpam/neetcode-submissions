class Solution {
public:
    vector<int>p;
    vector<int>rank;
    int find(int x){
        if(p[x]!=x){
            p[x]=find(p[x]);
        }
        return p[x];
    }
    void unite(int x,int y){
        int px=find(x),py=find(y);
        if(rank[px]<rank[py]){
            p[px]=py;
        }else if(rank[px]>rank[py]){
            p[py]=px;
        }else{
            p[py]=px;
            rank[px]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
          int n=e.size();
          p.resize(n);
          rank.resize(n,0);
          vector<int>res(2);
          for(int i=0;i<n;i++) p[i]=i;
          for(int i=0;i<n;i++){
             int x=e[i][0]-1,y=e[i][1]-1;
             int px=find(x),py=find(y);
             if(px==py){
                res[0]=x+1;
                res[1]=y+1;
             }else unite(x,y);
          }
          return res;
    }
};
