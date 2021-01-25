class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        dis[m-1][n-1] = 0;
        
        queue<pair<int, int>> pos;
        pos.push({m-1, n-1});
        
        vector<vector<int>> dirs{{}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        
        while(!pos.empty())
        {
            int size = pos.size();
            while(size-->0)
            {
                pair<int, int> cur = pos.front();
                pos.pop();
                
                for(auto i{1}; i<=4; i++)
                {
                    int nx = cur.first + dirs[i][0];
                    int ny = cur.second + dirs[i][1];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n)
                    {
                        int ndis = 0;
                        if(grid[nx][ny] == i)
                        {
                            ndis = dis[cur.first][cur.second];
                        }
                        else
                        {
                            ndis = dis[cur.first][cur.second] + 1;
                        }
                        
                        if(dis[nx][ny] > ndis)
                        {
                            pos.push({nx, ny});
                            dis[nx][ny] = ndis;
                        }
                    }
                }
            }
        }
        
        return dis[0][0];
        
    }
};
