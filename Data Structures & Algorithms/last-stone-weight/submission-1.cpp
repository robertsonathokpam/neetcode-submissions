class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int s:stones) pq.push(s);
        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            int b=0;
            if(!pq.empty()){
                b=pq.top();
            }else break;
            pq.pop();
            int diff=a-b;
            if(diff>=0){
                pq.push(diff);
            }
        }
        return (int)pq.top();
    }
};
