class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>mp;
        for(char c:tasks){
            mp[c]++;
        }
        int maxi=0;
        for(auto it:mp){
            maxi=max(maxi,it.second);
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second==maxi){
                cnt++;
            }
        }
         if(maxi==1){
            return tasks.size();
         }
            int x=n+1;
            int y=maxi-1;
            int res=x*y+cnt;
            return max((int)tasks.size(),res);
    }
};
