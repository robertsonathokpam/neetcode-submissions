class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int sum=0;
        int cnt=0; 
        int n=p.size();
        int l=0,r=n-1;
        while(l<=r){
            if(p[l]+p[r]<=limit){
                l++;
                r--;
            }else r--;
            cnt++;
        }
        return cnt;
    }
};