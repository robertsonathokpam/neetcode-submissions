class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pair<int,int>>pq;
        int n=p.size();
        for(int i=0;i<n;i++){
          int dist=p[i][0]*p[i][0]+p[i][1]*p[i][1];
          pq.push({-dist,i});
        }
        vector<vector<int>>res;
        while(k-- && !pq.empty()){
            auto [v,i]=pq.top();
            res.push_back(p[i]);
            pq.pop();
        }
        return res;
    }
};
