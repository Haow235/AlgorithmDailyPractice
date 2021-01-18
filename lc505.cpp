class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        int n = maze.size(), m = maze[0].size();
        // vector<vector<int>> visited
        // we use -1 to represent the cell has been visited
        
        maze[start[0]][start[1]] = -1;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        return shortestDistanceUtil(maze, start, destination, dp);
        
        
    }
    
private:
    vector<vector<int>> direcs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int shortestDistanceUtil(vector<vector<int>>& maze, vector<int> start, vector<int>& dest, vector<vector<int>>& dp)
    {
        if(start[0] == dest[0] && start[1] == dest[1])
            return 0;
        
        if(dp[start[0]][start[1]] != 0)
            return dp[start[0]][start[1]];
        
        // maze[start[0]][start[1]] = -1;
        
        int mindis = INT_MAX;
        int steps = 0;
        for(auto i{0}; i<4; i++)
        {
            vector<int> next = findnexthop(maze, start, direcs[i], &steps);
            if(maze[next[0]][next[1]] == 0)
            {
                // cout<<start[0] << ' ' << start[1] << endl;
                // cout<<next[0] << ' ' << next[1]<<endl;
                // cout<<steps<<endl;
                maze[next[0]][next[1]] = -1;
                int nextsteps = shortestDistanceUtil(maze, next, dest, dp);
                if(nextsteps != -1)
                    mindis = min(mindis, steps + nextsteps);
                maze[next[0]][next[1]] = 0;
            }
        }
        
        // maze[start[0]][start[1]] = 1;
        
        if(mindis == INT_MAX)
            return mindis = -1;
        
        dp[start[0]][start[1]] = mindis;
        
        return mindis;
    }
    
    vector<int> findnexthop(vector<vector<int>>& maze, vector<int> start, vector<int>& direc, int* steps)
    {
        *steps = 0;
        
        while(start[0]>=0 && start[0]<maze.size() && start[1]>=0 && start[1]<maze[0].size() && maze[start[0]][start[1]] != 1)
        {
            start[0] += direc[0];
            start[1] += direc[1];
            
            *steps = *steps + 1;
        }
        
        start[0] -= direc[0];
        start[1] -= direc[1];
        *steps = *steps - 1;
        
        // maze[start[0]][start[1]] = -1;
        return start;
    }
};
