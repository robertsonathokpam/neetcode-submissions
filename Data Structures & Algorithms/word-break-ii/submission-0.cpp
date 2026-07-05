class Solution {
public:
    unordered_set<string>st;
    vector<vector<string>>res;
    int n;
    void fn(int i,string s,vector<string>curr){
       if(i==n){
          res.push_back(curr);
       }
       for(int j=i;j<n;j++){
          string x=s.substr(i,j-i+1);
          if(st.count(x)){
             curr.push_back(x);
             fn(j+1,s,curr);
             curr.pop_back();
          }
       }
    }
    vector<string> wordBreak(string s, vector<string>& word) {
        n=s.size();
        for(string w:word){
           st.insert(w);
        }
        vector<string>curr;
        fn(0,s,curr);
        vector<string>ans;
        for(int i=0;i<res.size();i++){
           string curr="";
           for(int j=0;j<res[i].size();j++){
               curr+=res[i][j];
               if(j!=res[i].size()-1) curr+=" ";
           }
           ans.push_back(curr);
        }
        return ans;
    }
};