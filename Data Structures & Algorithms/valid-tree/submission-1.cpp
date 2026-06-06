class Solution {
public:
    bool validTree(int n, vector<vector<int>>& e) {
        queue<pair<int,int>>q;
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        q.push({0,-1});
        vis[0]=1;
        while(!q.empty()){
            auto [u,p]=q.front();
            q.pop();
            for(int v:adj[u]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push({v,u});
                }else{
                    if(p!=v){
                        return false;
                    }
                }
            } 
        }

        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
