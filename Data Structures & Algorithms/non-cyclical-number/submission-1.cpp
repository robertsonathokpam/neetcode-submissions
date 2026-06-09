class Solution {
public:
    bool isHappy(int n) {
        string s=to_string(n);
        set<int>st;
        while(1){
            int res=0;
            for(char c:s){
               res+=(c-'0')*(c-'0');
            }
            if(res==1){
                return true;
            }
            if(st.count(res)){
                return false;
            }
            st.insert(res);
            s=to_string(res);
        }
        return false;
    }
};
