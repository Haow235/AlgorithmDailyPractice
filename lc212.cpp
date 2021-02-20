struct Node
{
    bool isword = false;
    vector<Node*> next;
    
    Node():next(26, nullptr){}
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        int wn = words.size();
        
        // build a trie to store all the words
        Node* root = new Node();
        for(auto& s: words)
        {
            Node* curnode = root;
            for(auto c: s)
            {
                if(curnode->next[c-'a'] == nullptr)
                {
                    curnode->next[c-'a'] = new Node();
                }
                
                curnode = curnode->next[c-'a'];
            }
            
            curnode->isword = true;
        }
        
        // search if a word exist in the board
        // go through the board, use DFS to check if there exist a word start from cur location
        set<string> re;
        for(auto i{0}; i<m; i++)
        {
            for(auto j{0}; j<n; j++)
            {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                dfs(board, i, j, root, re, "", visited);
            }
        }
        
        vector<string> ree(re.begin(), re.end());
        
        return ree;
    }
    
private:
    void dfs(vector<vector<char>>& board, int i, int j, Node* root, set<string>& re, string curstring, vector<vector<bool>>& visited)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())
            return;
        
        if(visited[i][j])
            return;
        
        char c = board[i][j];
        if(root->next[c-'a'] == nullptr)
            return;
        
        curstring += c;
        root = root->next[c-'a'];
        visited[i][j] = true;
        
        if(root->isword)
        {
            re.insert(curstring);
        }
        
        dfs(board, i+1, j, root, re, curstring, visited);
        dfs(board, i-1, j, root, re, curstring, visited);
        dfs(board, i, j+1, root, re, curstring, visited);
        dfs(board, i, j-1, root, re, curstring, visited);
        
        visited[i][j] = false;
    }
};
