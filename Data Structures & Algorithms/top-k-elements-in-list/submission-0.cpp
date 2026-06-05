class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int,int>mp;
       priority_queue<pair<int,int>>pq;
       for(int num:nums) mp[num]++;
       for(auto it:mp){
          pq.push({-it.second,it.first});
          if(pq.size()>k){
            pq.pop();
          }
       }
       vector<int>res;
       while(!pq.empty()){
         res.push_back(pq.top().second);
         pq.pop();
       }       
       return res;
    }
};
