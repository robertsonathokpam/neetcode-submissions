class Solution {
public:
    bool fn(unordered_map<char,int>& mp,int k){
        int cnt=0;
        int maxi=0;
        char c='.'; 
        for(auto [k,v]:mp){
            if(v>maxi){
                maxi=v;
                c=k;
            }
        }
        for(auto [k,v]:mp){
            if(c!=k){
                cnt+=v;
            }
        }
        return cnt<=k;
    }
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int res=0;
        int l=0;
        for(int r=0;r<n;r++){
           mp[s[r]]++;
           while(!fn(mp,k)){
              mp[s[l]]--;
              if(mp[s[l]]==0) mp.erase(s[l]);
              l++;
           }
           res=max(res,r-l+1);
        }
        return res;
    }
};
