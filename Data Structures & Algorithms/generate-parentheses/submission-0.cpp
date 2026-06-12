class Solution {
public:  
    vector<string>res;
    
    bool valid(string s){
        int cnt=0;
        for(char c: s){
           cnt+=(c=='(');
           cnt-=(c==')');
           if(cnt<0) return false;
        }
        return cnt==0;
    }

    void fn(int n,string s){
        if(s.size()==2*n){
           if(valid(s)){
              res.push_back(s);
           }
           return;
        }

        fn(n,s+'(');
        fn(n,s+')');
    }
    vector<string> generateParenthesis(int n) {
        res.clear();
        fn(n,"");
        return res;
    }
};
