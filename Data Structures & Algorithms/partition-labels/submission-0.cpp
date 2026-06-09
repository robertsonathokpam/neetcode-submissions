class Solution {
   public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<vector<int>> pref(n, vector<int>(26, 0));
        pref[0][s[0] - 'a'] = 1;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1];
            pref[i][s[i] - 'a']++;
        }

        vector<int> res;
        int prev = 0;
        for (int r = 0; r < n; r++) {
            bool flag = true;
            for (int k = 0; k < 26; k++) {
                int left = pref[r][k] - (prev > 0 ? pref[prev - 1][k] : 0);
                int right = pref[n - 1][k] - pref[r][k];

                if (left > 0 && right > 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(r - prev +1);
                prev = r+1;
            }
        }

        return res;
    }
};
