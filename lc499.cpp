class Solution {
public:
    
    /*We can use the Dijkstra's algorithm for this question
    1. if the ball start from i, end at j, then we can see there's an edge from i to j
    2. there's an exceptence is that if the ball meet the hold along the way, then the edge would be from i to hole
    3. to return the path, we also need to keep track of the paths to get i, and update the paths to the j from i
    */
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        dis[ball[0]][ball[1]] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pos; // dis, x, y
        pos.push({0, ball[0], ball[1]});
        
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        // visited[ball[0]][ball[1]] = true;
        vector<vector<string>> paths(m, vector<string>(n, ""));
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<char> ds{'d', 'u', 'r', 'l'};
        
        while(!pos.empty())
        {
            vector<int> cur = pos.top();
            pos.pop();
            for(auto i{0}; i<4; i++)
            {
                int steps = 0;
                int nx = cur[1], ny = cur[2];
                while(nx>=0 && nx<m && ny>=0 && ny<n && maze[nx][ny] == 0)
                {
                    steps++;
                    if(nx == hole[0] && ny == hole[1])
                        break;
                    
                    nx += dirs[i][0];
                    ny += dirs[i][1];
                }
                
                steps--;
                if(nx != hole[0] || ny != hole[1])
                {
                    nx -= dirs[i][0];
                    ny -= dirs[i][1];
                }
                
                if(nx != cur[1] || ny != cur[2])
                {
                    if(dis[nx][ny] > dis[cur[1]][cur[2]] + steps)
                    {
                        dis[nx][ny] = dis[cur[1]][cur[2]] + steps;
                        paths[nx][ny] = paths[cur[1]][cur[2]] + ds[i];
                        if(nx != hole[0] || ny != hole[1])
                        {
                            pos.push({dis[nx][ny], nx, ny});
                        }
                    }
                    else if(dis[nx][ny] == dis[cur[1]][cur[2]] + steps)
                    {
                        paths[nx][ny] = min(paths[cur[1]][cur[2]] + ds[i], paths[nx][ny]);
                        if(nx != hole[0] || ny != hole[1])
                        {
                            pos.push({dis[nx][ny], nx, ny});
                        }
                    }
                }
                
                
            }
        }
        
        if(paths[hole[0]][hole[1]] == "")
            return "impossible";
        
        return paths[hole[0]][hole[1]];
    }
};
