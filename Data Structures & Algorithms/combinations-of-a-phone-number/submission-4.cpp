class Solution {
   public:
    unordered_map<int, vector<char>> mp;
    string s;
    vector<string> res;
    void fn(int ind, string curr) {

        if (ind == s.size()) {
            if(!curr.empty()) res.push_back(curr);
            return;
        }

        vector<char> x = mp[s[ind] - '0'];
        for (int i = 0; i < x.size(); i++) {
            curr.push_back(x[i]);
            fn(ind + 1, curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        mp.reserve(9);
        mp[2]={'a','b','c'};
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};
        s = digits;
        //if(s=="") return res;
        fn(0,"");
        return res;
    }
};
