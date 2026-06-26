class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {

    unordered_map<string,set<string>>mp,res;
    unordered_map<string,string>name;    
        for(int i=0;i<a.size();i++){
            for(int j=1;j<a[i].size();j++){
                name[a[i][j]]=a[i][0];
                mp[a[i][1]].insert(a[i][j]);
                mp[a[i][j]].insert(a[i][1]);
            }
        }
        
        unordered_map<string,int>vis;

        for(auto [s,z]:mp){
            if(!vis.count(s)){
                vis[s]++;
                queue<string>q;
                q.push(s);
                while(!q.empty()){
                    auto u=q.front();
                    res[s].insert(u);
                    q.pop();
                    for(string v:mp[u]){
                        if(!vis.count(v)){
                            vis[v]++;
                            q.push(v);
                        }
                    } 
                }
            }
        }

        vector<vector<string>>ans;

        for(auto [k,v]:res){
            vector<string>curr;
            curr.push_back(name[k]);
            for(auto it:v){
                curr.push_back(it);
            }
           // sort(curr.begin(),curr.end());
            ans.push_back(curr);
        }
      return ans;
    }
};