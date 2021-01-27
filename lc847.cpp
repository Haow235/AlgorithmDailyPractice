class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = 1<<n;
        
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        
        queue<pair<int, int>> pos;
        
        
        for(auto i{0}; i<n; i++)
        {
            pos.push({i, 1<<i});
            dis[i][1<<i] = 0;
        }
        
        while(!pos.empty())
        {
            pair<int, int> cur = pos.front();
            pos.pop();
            
            if(cur.second == m-1)
                return dis[cur.first][cur.second];
            
            for(auto i: graph[cur.first])
            {
                int mask = cur.second | (1<<i);
                if(dis[i][mask] > dis[cur.first][cur.second] + 1)
                {
                    dis[i][mask] = dis[cur.first][cur.second]+1;
                    pos.push({i, mask});
                }
            }
            
        }
        
        return -1;
        
    }
};
