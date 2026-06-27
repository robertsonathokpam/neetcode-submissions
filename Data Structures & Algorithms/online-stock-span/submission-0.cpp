class StockSpanner {
public:
    int cnt=0;
    stack<pair<int,int>>st;
    StockSpanner() {
        cnt=0;
    }
    
    int next(int price) {
        int res=0;
        cnt++;
           while(!st.empty() && st.top().first<=price){
              st.pop();
           }
           if(!st.empty()) res=cnt-st.top().second;
           else res=cnt;
           st.push({price,cnt});
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */