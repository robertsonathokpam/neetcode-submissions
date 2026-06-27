class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        stack<int> st;
        for (int a : A) {
            if (a < 0) {
                    while (!st.empty() && st.top()>0 && st.top() < abs(a)) {
                        st.pop();
                    }
                    if (!st.empty() && st.top()>0 && st.top() == abs(a))
                        st.pop();
                    else if (st.empty() || st.top()<0 )
                        st.push(a);
                }else
                st.push(a);
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};