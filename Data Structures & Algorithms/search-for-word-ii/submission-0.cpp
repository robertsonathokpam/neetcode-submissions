class Solution {
public:
    int n,m;
    vector<vector<int>>vis;
    struct Node{
        Node* c[26];
        bool end;
        
        Node(){
          for(int i=0;i<26;i++) {
            c[i]=nullptr;
          }
          end=false;
        }
        
    };

    Node* root;
    Solution(){
        root=new Node();
    }

    void add(string s){
        Node* curr=root;
        for(char w:s){
            if(curr->c[w-'a']==nullptr){
                curr->c[w-'a']=new Node();
            }
            curr=curr->c[w-'a'];
        }
        curr->end=true;
    }

    unordered_set<string>res,z;
    //vector<string>ans;

    void dfs(int r,int c,Node* curr,vector<vector<char>>& board,string& s){
      
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        if(curr->end==true){
                res.insert(s);
                //ans.push_back(s);
               // return;
        }
        
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc]){
                if(curr->c[board[nr][nc]-'a']!=nullptr){
                    vis[nr][nc]=1;
                    s.push_back(board[nr][nc]);
                    dfs(nr,nc,curr->c[board[nr][nc]-'a'],board,s);
                    s.pop_back();
                    vis[nr][nc]=0;
                }
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size();
        m=board[0].size();
        for(string w:words){
            z.insert(w);
            add(w);
        }
        Node* curr=root;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string s="";
                vis.assign(n,vector<int>(m,0));
                if(curr->c[board[i][j]-'a']!=nullptr){
                    vis[i][j]=1;
                    s.push_back(board[i][j]);
                    dfs(i,j,curr->c[board[i][j]-'a'],board,s);
                }
            }
        }
        vector<string>ans(res.begin(),res.end());
        return ans;
    }
};