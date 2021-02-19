class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        
        vector<vector<int>> palin(n, vector<int>(n, 0));
        for(auto i{0}; i<n; i++)
        {
            palin[i][i] = 1;
            for(auto j{i+1}; j<n; j++)
            {
                int k = i, m = j;
                while(k<=m)
                {
                    if(s[k] != s[m])
                        break;
                    
                    k++;
                    m--;
                }
                
                if(k>m)
                    palin[i][j] = 1;
            }
        }
        
        vector<string> cur;
        vector<vector<string>> re;
        dfs(s, palin, 0, cur, re);
        return re;
    }
    
private:
    void dfs(string& s, vector<vector<int>>& palin, int p, vector<string>& cur, vector<vector<string>>& re)
    {
        if(p == s.size())
        {
            re.push_back(cur);
            return;
        }
            
        for(auto i{p}; i<palin.size(); i++)
        {
            if(palin[p][i])
            {
                cur.push_back(s.substr(p, i-p+1));
                dfs(s, palin, i+1, cur, re);
                cur.pop_back();
            }
        }
    }
};
