class Solution {
public:
    unordered_map<string, int> mp;
    vector<int> dp;
    int n;

    bool wordBreak(string s, vector<string>& w) {

        n = s.size();
        for (string s : w)  mp[s]++;
        dp.assign(n+1, -1);
        dp[n]=1;
        for (int ind = n - 1; ind >= 0; ind--) {
            int k = 0;
            for (int i = ind; i < n; i++) {
                string x = s.substr(ind, i - ind + 1);
                if (mp.count(x)) {
                    //k |= fn(i + 1, s);
                    k|=dp[i+1];
                }
            }
            dp[ind]=k;
        }
         return dp[0]; 
        //return fn(0, s);
    }
};
