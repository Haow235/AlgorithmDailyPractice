struct Node{
    vector<Node*> next;
    int index;
    
    Node():next(26, nullptr), index(-1){}
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        // build to trie, one build with the word from front, the other build from the word end
        froot = new Node();
        eroot = new Node();
        
        for(auto i{0}; i<words.size(); i++)
        {
            Node* curnode = froot;
            for(int j = 0; j<words[i].size(); j++)
            // for(auto c: words[i])
            {
                if(curnode->next[words[i][j]-'a'] == nullptr)
                {
                    Node* newnode = new Node();
                    curnode->next[words[i][j]-'a'] = newnode;
                }
                
                curnode = curnode->next[words[i][j]-'a'];
            }
            
            curnode->index = i;
        }
        
        // cout<<"build finished"<<endl;
        
        for(auto i{0}; i<words.size(); i++)
        {
            Node* curnode = eroot;
            // cout<<words[i]<<endl;
            for(int j = words[i].size()-1; j>=0; j--)
            {
                if(curnode->next[words[i][j]-'a'] == nullptr)
                {
                    Node* newnode = new Node();
                    curnode->next[words[i][j]-'a'] = newnode;
                }
                
                curnode = curnode->next[words[i][j]-'a'];
            }
            
            curnode->index = i;
        }
        
        // cout<<"build finished"<<endl;
        
        // when match, check if front equal to end, if equal, move to next level, else, break
        // if one trie reach null, check if palindrome of the rest of the other trie
        set<vector<int>> re;
        match(froot, eroot, re);
        
        vector<vector<int>> result(re.begin(), re.end());
        
        return result;
    }
    
private:
    Node* froot;
    Node* eroot;
    
    void match(Node* fcur, Node* ecur, set<vector<int>>& re)
    {
        // base case => fcur is a word or ecur is a word
        if(fcur->index != -1)
        {
            findPalindrome(ecur, "", fcur->index, re, true);
        }
        if(ecur->index != -1)
        {
            findPalindrome(fcur, "", ecur->index, re, false);
        }

        for(auto i{0}; i<26; i++)
        {
            if(fcur->next[i] != nullptr && ecur->next[i] != nullptr)
            {
                match(fcur->next[i], ecur->next[i], re);
            }
        }

    }
    
    void findPalindrome(Node* curnode, string curs, int index, set<vector<int>>& re, bool isfirst)
    {
        if(curnode->index != -1 && curnode->index != index)
        {
            if(isPalindrome(curs))
            {
                if(isfirst)
                    re.insert({index, curnode->index});
                else
                    re.insert({curnode->index, index});
            }
        }
        
        for(auto i{0}; i<26; i++)
        {
            if(curnode->next[i] != nullptr)
            {
                findPalindrome(curnode->next[i], curs+string(1, 'a'+i), index, re, isfirst);
            }
        }
        
        return;
    }
    
    bool isPalindrome(string& s)
    {
        // bool re = true;
        
        int left = 0, right = s.size()-1;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            
            left++;
            right--;
        }
        
        return true;
    }
};
