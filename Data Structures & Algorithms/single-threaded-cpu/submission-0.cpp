class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            nums[i].push_back(i);
        }

        sort(nums.begin(),nums.end());

        vector<int>res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        int i=0;
        long long t=0;
        while(i<n || pq.size()){
            if(pq.empty()){
               t=max(t,1LL*nums[i][0]);
            }
            while(i<n && 1LL*nums[i][0]<=t){
                pq.push({nums[i][1],nums[i][2]});
                i++;
            }
            auto [time,ind]=pq.top();
            pq.pop();
            t+=time;
            res.push_back(ind);
        }
        return res;
    }
};