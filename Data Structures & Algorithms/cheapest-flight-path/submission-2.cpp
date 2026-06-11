class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dis(n,1e5);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        //queue<tuple<int, int, int>> pq;
        pq.push({0,src,0});
        dis[src]=0;
        vector<vector<pair<int,int>>>adj(n);
        
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int>stops(n,1e5);
        while(!pq.empty()){
            auto [w,u,cnt]=pq.top();
            pq.pop();
            if(u==dst) return w;
            if(cnt>k) continue;
            if(stops[u]<=cnt) continue;
            for(auto [v,nw] :adj[u]){
                    pq.push({nw+w,v,cnt+1});
                }
        }

        return -1;
    }
};
