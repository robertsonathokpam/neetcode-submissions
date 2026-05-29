class MinStack {
public:
stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
       if(!st.empty()) st.pop();
    }
    
    int top() {
        if(!st.empty()) return st.top();
    }
    
    int getMin() {
        stack<int>nums;
        int mini=INT_MAX;
        while(!st.empty()){
           mini=min(mini,st.top());
           nums.push(st.top());
           st.pop();
        }
        while(!nums.empty()){
            st.push(nums.top());
            nums.pop();
        }
        return mini;
    }
};
