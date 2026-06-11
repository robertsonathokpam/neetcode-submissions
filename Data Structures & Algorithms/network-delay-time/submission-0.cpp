class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto [w,u]=pq.top();
            pq.pop();
            for(auto [v,nw]:adj[u]){
                if(dist[v]>nw+dist[u]){
                    dist[v]=nw+dist[u];
                    pq.push({nw,v});
                }
            }
        }
        int res=-1;
        for(int i=1;i<=n;i++){
            res=max(res,dist[i]);
        }

        if(res==INT_MAX) return -1;
        return res;
    }
};
