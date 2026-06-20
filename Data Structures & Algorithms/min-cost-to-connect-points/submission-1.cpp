// LC-1584
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();

        //map<pair<int,int>,vector<tuple<int,int,int>>>mp;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                    int dist=abs(points[i][1]-points[j][1])+abs(points[i][0]-points[j][0]);
                    adj[i].push_back({dist,j});
                    adj[j].push_back({dist,i});
            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,0});

        int cost=0;
        
        vector<int>vis(n,0);
        //st.insert({points[0][0],points[0][1]});

        while(!pq.empty()){
            auto [w,u]=pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u]=1;
            cost+=w;
            vector<pair<int,int>>nums = adj[u];
            
            for(int i=0;i<nums.size();i++){
                auto [nw,v]=nums[i];
                pq.push({nw,v});
            }
        }

        return cost;
    }
};