class Solution {
public:
    vector<int>pse,nse;
    int n;
    void P(vector<int>&h){
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            if(!st.empty()) pse[i]=st.top();
            else pse[i]=-1;
            st.push(i);
        }
    }

    void N(vector<int>&h){
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            if(!st.empty()) nse[i]=st.top();
            else nse[i]=n;
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& h) {
        n=h.size();
        pse.resize(n);
        nse.resize(n);
        P(h);
        N(h);
        int area=0;
        for(int i=0;i<n;i++){
            int w=nse[i]-pse[i]-1;
            area=max(area,w*h[i]);
        }
        return area;
    }
};