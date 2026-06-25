

class WordDictionary {
public:
    struct node {
        node* c[26];
        bool end;
        node() {
            end = false;
            for (int i = 0; i < 26; i++)
                c[i] = nullptr;
        }
    };
    node* root;
    //vector<int>dp;
    WordDictionary() { root = new node(); }

    void addWord(string word) {
        node* curr = root;
        for (char w : word) {
            if (curr->c[w - 'a'] == nullptr) {
                curr->c[w - 'a'] = new node;
            }
            curr = curr->c[w - 'a'];
        }
        curr->end = true;
    }

    int dfs(int ind, node* curr, string word) {
        
        if(ind==word.size()){
            return curr->end;
        }
        
        if (word[ind] == '.') {
            for (int i = 0; i < 26; i++) {
                if(curr->c[i]!=nullptr){
                    if(dfs(ind + 1, curr->c[i], word)){
                        return 1;
                    }
                }              
             }
             return 0;
        } else {
            if (curr->c[word[ind] - 'a'] == nullptr) {
                return 0;
            }
            return dfs(ind + 1, curr->c[word[ind] - 'a'], word);
        }
    }

    bool search(string word) {
        node* curr = root;
        //dp.assign(word.size()+2,-1);
        int k= dfs(0,curr,word);
        if(k==-1 || k==0) return false;
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
