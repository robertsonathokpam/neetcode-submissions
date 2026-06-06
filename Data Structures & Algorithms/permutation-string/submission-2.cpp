class Solution {
   public:
    bool check(vector<int>& mp1, vector<int>& mp) {
        bool k = true;
        for (int i = 0; i < 26; i++) {
            if (mp1[i] != mp[i]) k = false;
        }
        return k;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26, 0), mp(26, 0);

        for (char c : s1) {
            mp1[c - 'a']++;
        }
        int n = s2.size();
        int l = 0, r = 0;
        while (r < n) {
            mp[s2[r] - 'a']++;
            if(r - l +1> s1.size()) {
                mp[s2[l] - 'a']--;
                l++;
            }
            if(r-l+1==s1.size() && check(mp1,mp)) return true;
            r++;
        }
        return false;
    }
};
