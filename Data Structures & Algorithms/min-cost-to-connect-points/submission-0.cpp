// LC-1584
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();

        map<pair<int,int>,vector<tuple<int,int,int>>>mp;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                    int dist=abs(points[i][1]-points[j][1])+abs(points[i][0]-points[j][0]);
                    mp[{points[i][0],points[i][1]}].push_back({dist,points[j][0],points[j][1]});
                    mp[{points[j][0],points[j][1]}].push_back({dist,points[i][0],points[i][1]});
            }
        }

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;

        pq.push({0,points[0][0],points[0][1]});

        int cost=0;
        
        set<pair<int,int>>st;
        //st.insert({points[0][0],points[0][1]});

        while(!pq.empty()){
            auto [w,x,y]=pq.top();
            pq.pop();
            if(st.count({x,y})) continue;
            st.insert({x,y});
            cost+=w;
            vector<tuple<int,int,int>>v = mp[{x,y}];
            
            for(int i=0;i<v.size();i++){
                auto [nw,nx,ny]=v[i];
                pq.push({nw,nx,ny});
            }
        }

        return cost;
    }
};