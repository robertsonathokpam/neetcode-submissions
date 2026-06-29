//leetcode 895
class FreqStack {
public:
    unordered_map<int,int>freq,count;
    unordered_map<int,stack<int>>mp;
    int maxi=0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxi=max(maxi,freq[val]);
       // count[maxi]++;
        mp[freq[val]].push(val);   
    }
    
    int pop() {
       int k= mp[maxi].top();
       mp[maxi].pop();
       if(mp[maxi].size()==0){
         maxi--;
       }
       freq[k]--;
       
       return k;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */