class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        unordered_set<string> st;
        for (string s : d)
            st.insert(s);
        int n = s.size();
        vector<int> dp(n + 1, 1e5);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 1 + dp[i - 1];
            for (int j = i; j >= 1; j--) {
                string x = s.substr(j - 1, i - j + 1);
                if (st.count(x)) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
            }
        }
        return dp[n];
    }
};