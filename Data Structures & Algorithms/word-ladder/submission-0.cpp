class Solution {
public:
    bool valid(string a,string b){
        int n=a.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) cnt++;
        }
        return cnt<2;
    }
    int ladderLength(string begin, string end, vector<string>& w) {
        int n=w.size();
        queue<pair<string,int>>q;
        q.push({begin,1});
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(w[i]==begin){
                vis[i]=1;
            }
        }

        while(!q.empty()){
            auto [s,cnt]=q.front();
            if(s==end){
                return cnt;
            }
            q.pop();
            for(int i=0;i<n;i++){
                if(!vis[i] && valid(s,w[i])){
                    vis[i]=1;
                    q.push({w[i],cnt+1});
                }
            }
        }

        return 0;
    }
};
