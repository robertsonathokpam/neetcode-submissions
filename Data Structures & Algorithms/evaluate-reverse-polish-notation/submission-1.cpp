class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<string>st;
        for(string c:s){
            if(st.empty()) st.push(c);
            else if(c=="+" || c=="-" || c=="*" || c=="/"){
                int a=stoi(st.top());
                st.pop();
                int b=stoi(st.top());
                st.pop();
                if(c=="+"){
                    int k=a+b;
                    string z=to_string(k);
                    st.push(z);
                }else if(c=="-"){
                    int k=b-a;
                    string z=to_string(k);
                    st.push(z);
                }else if(c=="*"){
                    int k=a*b;
                    string z=to_string(k);
                    st.push(z);
                }else{
                    int k=b/a;
                    string z=to_string(k);
                    st.push(z);
                }
            }else st.push(c);
        }
        return stoi(st.top());
    }
};
