class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curnode = root;
        for(auto c: word)
        {
            if(curnode->next[c-'a'] == nullptr)
            {
                Node* newnode = new Node();
                curnode->next[c-'a'] = newnode;
            }
            
            curnode = curnode->next[c-'a'];
        }
        
        curnode->isWorld = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curnode = root;
        for(auto c: word)
        {
            if(curnode->next[c-'a'] == nullptr)
                return false;
            
            curnode = curnode->next[c-'a'];
        }
        
        if(curnode->isWorld)
            return true;
        
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curnode = root;
        for(auto c: prefix)
        {
            if(curnode->next[c-'a'] == nullptr)
                return false;
            
            curnode = curnode->next[c-'a'];
        }
        
        return true;
    }
    
private:
    struct Node{
        vector<Node*> next;
        bool isWorld = false;
        
        Node():next(26, nullptr){}
    };
    
    Node* root = nullptr;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
