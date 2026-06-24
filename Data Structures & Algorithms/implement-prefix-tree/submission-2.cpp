class PrefixTree {
public:
    struct node {
        node* c[26];
        bool end;
        node(){
          for(int i=0;i<26;i++) c[i]=nullptr;
          end=false;
        }       
    };

    node* root;
    PrefixTree() {
        root=new node();
    }
    
    void insert(string word) {
        node* curr=root;
        for(char w:word){
            if(curr->c[w-'a']==nullptr){
                curr->c[w-'a']=new node();
            }
            curr=curr->c[w-'a'];
        }
        curr->end=true;
    }
    
    bool search(string word) {
        node* curr=root;
        for(char w:word){
            if(curr->c[w-'a']==nullptr){
                return false; 
            }
            curr=curr->c[w-'a'];
        }
        return curr->end; 
    }
    
    bool startsWith(string prefix) {
        node* curr=root;
        for(char w:prefix){
            if(curr->c[w-'a']==nullptr){
                return false; 
            }
            curr=curr->c[w-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
