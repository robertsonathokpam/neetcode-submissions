class Solution {
public:
    unordered_set<string> st;

    int openLock(vector<string>& deadends, string target) {

        //string s = "0000";
        for (string s : deadends) {
            if(s=="0000") return -1;
            st.insert(s);
        }

        queue<pair<string,int>> q;
        q.push({"0000",0});

        while (!q.empty()) {
            auto [s,cnt]=q.front();
            q.pop();
            if(s==target) return cnt;
            for (int i = 0; i < 4; i++) {
                    string res=s;
                    res[i]=(char)((int)s[i]-1);
                    if(s[i]=='0'){
                       res[i]='9';
                    }
                    if(!st.count(res)){
                        st.insert(res);
                        q.push({res,cnt+1});
                    }
                    res[i]=(char)((int)s[i]+1);
                    if(s[i]=='9'){
                       res[i]='0';
                    }
                    if(!st.count(res)){
                        st.insert(res);
                        q.push({res,cnt+1});
                    }
                }
            }
        return -1;
    }
};