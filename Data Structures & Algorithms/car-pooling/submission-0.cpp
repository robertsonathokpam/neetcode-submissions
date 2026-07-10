class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](const vector<int>&a,const vector<int>&b){
             return a[2]<b[2];
        });
        int n=trips[trips.size()-1][2];
        vector<int>diff(n+10,0);
        for(int i=0;i<trips.size();i++){
            diff[trips[i][1]]+=trips[i][0];
            diff[trips[i][2]]-=trips[i][0];
        }
        for(int i=0;i<=n;i++){
            if(i-1>=0) diff[i]+=diff[i-1];
            if(diff[i]>capacity) return false;
        }
        return true;
    }
};