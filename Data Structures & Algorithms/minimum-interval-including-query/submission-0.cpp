class Solution {
public:
    using Pair = pair<int, int>;

    struct Compare {
        bool operator()(const Pair& a, const Pair& b) {
            return abs(a.first - a.second) > abs(b.first - b.second);
        }
    };

    bool fn(int x, int a, int b) { return a <= x && x <= b; }

    vector<int> minInterval(vector<vector<int>>& nums, vector<int>& q) {
        //vector<int>q=Q;
        vector<pair<int,int>>qr(q.size());
        for(int i=0;i<q.size();i++){
             qr[i].first=q[i];
             qr[i].second=i;
        }
        sort(qr.begin(),qr.end());
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < q.size(); i++) {
            mp[qr[i].second] = i;
        }
        //sort(q.begin(), q.end());
        priority_queue<Pair, vector<Pair>, Compare> pq;

        vector<int> ans(q.size(), -1);
        int j = 0;
        for (int i = 0; i < q.size(); i++) {
            int curr = qr[i].first;
            while (j < nums.size() && curr >= nums[j][0]) {
                pq.push({nums[j][0], nums[j][1]});
                j++;
            }
            while (!pq.empty() && curr > pq.top().second) {
                pq.pop();
            }

            if (!pq.empty()) {
                auto [l, r] = pq.top();
                if (fn(curr, l, r)) {
                    ans[qr[i].second] = r - l + 1;
                }
            }
        }
        return ans;
    }
};