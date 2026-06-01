class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>>mp;
        vector<vector<string>>res;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
           sort(s.begin(),s.end());
           mp[s].push_back(i);
        }
        res.resize(mp.size());
        int j=0;
        for(auto [k,v]:mp){
            for(int i=0;i<v.size();i++){
               res[j].push_back(strs[v[i]]);
            }
            j++;
        }
        return res;
    }
};
