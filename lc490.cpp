class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size(), m=maze[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        queue<vector<int>> pos;
        pos.push(start);
        visited[start[0]][start[1]] = 1;
        
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while(!pos.empty())
        {
            vector<int> cur = pos.front();
            pos.pop();
            
            if(cur[0] == destination[0] && cur[1] == destination[1])
                return true;
            
            for(auto i{0}; i<4; i++)
            {
                int nx = cur[0];
                int ny = cur[1];
                
                while(nx >= 0 && nx<n && ny>=0 && ny<m && maze[nx][ny] == 0)
                {
                    nx += dirs[i][0];
                    ny += dirs[i][1];
                }
                
                nx -= dirs[i][0];
                ny -= dirs[i][1];
                
                if(visited[nx][ny] == 0)
                {
                    pos.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
            
        }
        
        return false;
        
    }
};
