class Solution {
public:  
    vector<string>res;
    int n;
    void fn(int o,int c,string s){
        if(s.size()==2*n){
           res.push_back(s);
           return;
        }

        if(o<n){
           s.push_back('(');
           fn(o+1,c,s);
           s.pop_back();
        }
        if(c<o){
           s.push_back(')');
           fn(o,c+1,s);
           s.pop_back();
        }
      
    }
    vector<string> generateParenthesis(int N) {
        n=N;
        res.clear();
        fn(0,0,"");
        return res;
    }
};
