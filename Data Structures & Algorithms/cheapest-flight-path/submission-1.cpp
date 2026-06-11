class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dis(n,1e5);
        //priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        queue<tuple<int, int, int>> pq;
        pq.push({0,src,0});
        dis[src]=0;
        vector<vector<pair<int,int>>>adj(n);
        
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        while(!pq.empty()){
            auto [w,u,cnt]=pq.front();
            pq.pop();
            for(auto [v,nw] :adj[u]){
                if(w+nw<dis[v]){
                    dis[v]=w+nw;
                    if(cnt<k) pq.push({dis[v],v,cnt+1});
                }
            }
        }

        int res=dis[dst];
        if(res==1e5) return -1;
        return res;
    }
};
