class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res=-1;
        priority_queue<int>pq;
        for(int num:nums) pq.push(num);
        while(k-- && !pq.empty()){
            
           if(k==0) res=pq.top();
            pq.pop();
        }
        return res;
    }
};
