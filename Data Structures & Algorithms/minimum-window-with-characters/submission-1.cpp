class Solution {
public:
    bool fn(unordered_map<char,int>&mp,unordered_map<char,int>&mp1){
        for(auto it:mp){
            if(!mp1.count(it.first)){
                return false;
            }
            if(mp1[it.first]<mp[it.first]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
       unordered_map<char,int>mp,mp1;
       for(char c:t) mp[c]++;
       int len=INT_MAX;
       int l=0;
       int i1=-1,i2=-1;
       for(int r=0;r<s.size();r++){
          mp1[s[r]]++;
          while(fn(mp,mp1)){
             //len=min(len,i-l+1);
             if(r-l+1<len){
                len=r-l+1;
                i1=l;
                i2=r;
             }
             mp1[s[l]]--;
             if(mp1[s[l]]==0) mp1.erase(s[l]);
             l++;
          }
       }
      string res="";
      if(i1==-1){
         return ""; 
      }
      for(int i=i1;i<=i2;i++){
        res+=s[i];
      }
      return res;
    }
};
