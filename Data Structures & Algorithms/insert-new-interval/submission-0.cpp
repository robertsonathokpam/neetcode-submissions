class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& nums) {
       vector<vector<int>>res;
       intervals.push_back({nums[0],nums[1]});
       int n=intervals.size();
       sort(intervals.begin(),intervals.end());
       int s,e;
       res.push_back({intervals[0][0],intervals[0][1]});
       for(int i=1;i<n;i++){
           s=intervals[i][0];
           e=intervals[i][1];
        
           auto& it=res.back();
           if(s<=it[1]){
               it[0]=min(it[0],s);
               it[1]=max(it[1],e);
           }else {
               res.push_back({s,e});
           }
       }
       return res;   
    }
};
