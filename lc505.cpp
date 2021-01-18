class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size(), m = maze[0].size();
        
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[start[0]][start[1]] = 0;
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> next; // dis, x, y
        next.push({0, start[0], start[1]});
        
        while(!next.empty())
        {
            vector<int> cur = next.top();
            next.pop();
            
            if(visited[cur[1]][cur[2]])
                continue; // we have visited this position before
            
            if(cur[1] == destination[0] && cur[2] == destination[1])
                return cur[0]; // if we find the dest, return the dis
            
            visited[cur[1]][cur[2]] = true;
            
            // update the distance to the neighbours of cur position
            for(int i{0}; i<4; i++)
            {
                int s = findDis(maze, cur[1], cur[2], i);
                if(s != 0)
                {
                    int tempdis = cur[0] + s;
                    int nextx = cur[1] + (s * directions[i][0]);
                    int nexty = cur[2] + (s * directions[i][1]);
                    if(tempdis < dis[nextx][nexty])
                    {
                        dis[nextx][nexty] = tempdis;
                        next.push({tempdis, nextx, nexty});
                    }
                }
            }
        }
        
        return -1;
    }
    
private:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int findDis(vector<vector<int>>& maze, int x, int y, int di)
    {
        int s = 0;
        while(x >= 0 && x<maze.size() && y >= 0 && y<maze[0].size() && maze[x][y] == 0)
        {
            x += directions[di][0];
            y += directions[di][1];
            s++;
        }
        
        return s-1;
    }
};
