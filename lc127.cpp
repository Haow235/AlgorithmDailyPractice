class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // edge case:
        // 1. begin word == endword
        // if(beginWord == endWord)
        //     return 0;
        
        // 2. one of the beginword or endword have 0 length => return 0
        
        // use a map to map a word to all the words that similar to this word(only have one different)
        unordered_map<string, vector<string>> adj;
        for(auto i{0}; i<wordList.size(); i++)
        {
            for(auto j{i+1}; j<wordList.size(); j++)
            {
                if(isSimilar(wordList[i], wordList[j]))
                {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        for(auto& s: wordList)
        {
            if(isSimilar(beginWord, s))
            {
                adj[beginWord].push_back(s);
            }
        }
        
        
        // Use BFS algorithm, start from the beginword, and each step add the similar words of current word to queue if that word has not been visited. Keep track of the steps along the way
        // The moment we find the endWord would be the end
        
        unordered_map<string, bool> visited;
        queue<string> pos;
        pos.push(beginWord);
        visited[beginWord] = true;
        
        int steps = 1;
        
        while(!pos.empty())
        {
            int size = pos.size();
            while(size-->0)
            {
                string cur = pos.front();
                pos.pop();
                
                if(cur == endWord)
                    return steps;
                
                for(auto& s: adj[cur])
                {
                    if(visited[s] == false)
                    {
                        pos.push(s);
                        visited[s] = true;
                    }
                }
            }
            
            steps++;
        }
        
        return 0;
        
    }
    
private:
    bool isSimilar(const string& lh, const string& rh)
    {
        int n = lh.size();
        int diffc = 0;
        for(auto i{0}; i<n; i++)
        {
            if(lh[i] != rh[i])
            {
                diffc++;
                if(diffc > 1)
                    return false;
            }
        }
        
        return true;
    }
};
