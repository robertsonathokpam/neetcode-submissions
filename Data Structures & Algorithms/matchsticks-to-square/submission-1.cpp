class Solution {
public:
    int sum=0,l=0;
    bool fn(int curr,int i,vector<int>&m,int cnt,vector<int>&vis){
        if(cnt==3) return true;
        if(curr==l){
            return fn(0,0,m,cnt+1,vis); 
        }
        for(int j=i;j<m.size();j++){
            if(vis[j] || curr+m[j]>l) continue;
            vis[j]=1;
            if(fn(curr+m[j],j+1,m,cnt,vis)) return true;
            vis[j]=0;
        }
        //vis[i]=0;
        return false;
    }
    bool makesquare(vector<int>& m) {
        for(int s:m) sum+=s;
        if(sum%4!=0) return false;
        vector<int>vis(m.size()+1,0);
        sort(m.rbegin(),m.rend());
        l=sum/4;
        return fn(0,0,m,0,vis);
    }
};