class Solution {
public:
    int countComponents(int n, vector<vector<int>>& e) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        int cnt=0;
        queue<int>q;
        for(int i=0;i<n;i++){
           if(!vis[i]){
              cnt++;
              vis[i]=cnt;
              q.push(i);
              while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v:adj[u]){
                    if(!vis[v]){
                        vis[v]=cnt;
                        q.push(v);
                    }
                }
              }
           }
           //q.clear();
        }
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(vis[i]);
        }
        return (int)st.size(); 
    }
};
