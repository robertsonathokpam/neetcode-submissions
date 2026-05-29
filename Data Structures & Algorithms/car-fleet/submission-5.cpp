class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        
        int n=p.size();
        vector<pair<int,int>>nums(n);
        for(int i=0;i<n;i++){
            nums[i].first=p[i];
            nums[i].second=s[i];
        }

        sort(nums.rbegin(),nums.rend());
        stack<double>st;

        for(int i=0;i<n;i++){
           double t=(double)(target-nums[i].first)/nums[i].second;
           if(!st.empty() && st.top()>=t){
           }else  st.push(t);
        }
        return st.size();
    }
};
