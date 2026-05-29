class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>st;
        int n=t.size();
        vector<int>res(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && t[i]>=t[(int)st.top()]){
                st.pop();               
            }
            if(st.empty()){
                res[i]=0;
            }else   res[i]=abs(i-st.top());
            st.push(i);
        }
        return res;
    }
};
