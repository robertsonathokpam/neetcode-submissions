class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& e) {
        queue<int>q;
        vector<int>ind(n);
        vector<vector<int>>adj(n);
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
            ind[e[i][1]]++;
        }
        vector<int>res(n);
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
                //res.push_back(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            res[n-1-cnt]=u;
            cnt++;
            for(int v:adj[u]){
                ind[v]--;
                if(ind[v]==0){
                    q.push(v);
                    //res.push_back(v);
                }
            }
        }
        if(cnt!=n){
            return {};
        }
        return res;
    }
};
