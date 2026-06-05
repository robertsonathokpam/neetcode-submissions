class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& e) {
        vector<vector<int>>adj(n);
        if(e.size()==0) return true;
        vector<int>ind(n,0);
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
            ind[e[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            cnt++;
            for(auto v:adj[u]){
                ind[v]--;
                if(ind[v]==0){
                    q.push(v);
                }
            }
        }
        return cnt==n;
    }
};
