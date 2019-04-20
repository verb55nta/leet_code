class Trie {
    
    struct Tree{
        //char c;
        bool fin;
        map<char,Tree*> nexts;

    };
    Tree *root;
   
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Tree;
    }
    
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        Tree* cur=root;
        
        for(auto c:word){
            
            if(cur->nexts.count(c)>0){
                cur = cur->nexts[c];
            }
            else{
                cur->nexts[c]= new Tree;
                cur=cur->nexts[c];
                cur->fin=false;
            }
            
        }
        cur->fin=true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        Tree* cur=root;
        
        for(auto c:word){
            
            if(cur->nexts.count(c)>0){
                cur=cur->nexts[c];
            }
            else return false;
            
        }
        
        if(cur->fin==true) return true;
        
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        Tree* cur=root;
        
        for(auto c:prefix){
            
            if(cur->nexts.count(c)>0){
                cur=cur->nexts[c];
            }
            else return false;
            
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