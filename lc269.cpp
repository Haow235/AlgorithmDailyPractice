class Solution {
public:
    string alienOrder(vector<string>& words) {
        // build adjacent matrix and indegree of each char
        vector<int> indegree(26, 0);
        vector<vector<bool>> adj(26, vector<bool>(26, false));
        vector<bool> isalienchar(26, false);
        int count = 0;
        
        // find all characters used in alien words
        for(string& word:words)
        {
            for(int i{0}; i<word.size(); i++)
            {
                if(!isalienchar[word[i]-'a'])
                {
                    isalienchar[word[i]-'a'] = true;
                    count++;
                }
            }
        }
        
        for(int i{0}; i<words.size()-1; i++)
        {
            // compare words[i] and words[i+1] to get the relative order of two characters
            int j=0;
            while(j<words[i].size() && j<words[i+1].size())
            {
                if(words[i][j] != words[i+1][j])
                {
                    if(adj[words[i+1][j]-'a'][words[i][j]-'a'])
                        return "";
                    
                    // update the adj matrix and indegree if we find a new edge
                    if(!adj[words[i][j]-'a'][words[i+1][j]-'a'])
                    {
                        adj[words[i][j]-'a'][words[i+1][j]-'a'] = true;
                        indegree[words[i+1][j]-'a']++;
                    }
                    
                    break;
                }
                j++;
            }
            
            if(j != words[i].size() && j==words[i+1].size())
            {
                return "";
            }
        }
        
        // find the relative order
        queue<int> nextchar;
        string re="";
        
        for(int i{0}; i<26; i++)
        {
            if(indegree[i] == 0 && isalienchar[i])
            {
                nextchar.push(i);
            }
        }
        
        while(!nextchar.empty())
        {
            int curchar = nextchar.front();
            nextchar.pop();
            
            // num++;
            re += ('a'+curchar);
            
            for(int i{0}; i<26; i++)
            {
                if(adj[curchar][i] == true)
                {
                    indegree[i]--;
                    if(indegree[i] == 0)
                    {
                        nextchar.push(i);
                    }
                }
            }
        }
        
        if(re.size() == count)
            return re;
        
        return "";
        
    }
};
