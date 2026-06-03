class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        for(char c:tasks){
            mp[c-'A']++;
        }
        sort(mp.begin(),mp.end());
        int maxi=(mp[25]-1)*n;
        int cnt=0;
        for(int i=24;i>=0;i--){
            maxi-=min(mp[25]-1,mp[i]);
        }
        return tasks.size()+max(0,maxi);
    
    }
};
