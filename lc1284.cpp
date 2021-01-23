class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, bool> visited;
        int mask = 0;
        for(int k{0}; k<m; k++)
        {
            for(int l{0}; l<n; l++)
            {
                if(mat[k][l] == 1)
                {
                    mask |= 1<<(k*m+l);
                }
            }
        }
        visited[mask] = true;
        
        queue<vector<vector<int>>> pos;
        pos.push(mat);
        
        int steps = 0;
        while(!pos.empty())
        {
            int size = pos.size();
            while(size-->0)
            {
                vector<vector<int>> cur = pos.front();
                pos.pop();

                bool target = true;
                for(int i{0}; i<m; i++)
                {
                    for(int j{0}; j<n; j++)
                    {
                        if(cur[i][j] == 1)
                        {
                            target = false;
                            break;
                        }
                            // break;
                    }
                }

                if(target)
                    return steps;

                for(int i{0}; i<m; i++)
                {
                    for(int j{0}; j<n; j++)
                    {
                        // flip this position
                        vector<vector<int>> temp = cur;
                        temp[i][j] = (temp[i][j] + 1)%2;
                        if(i-1>=0)
                            temp[i-1][j] = (temp[i-1][j] + 1)%2;
                        if(i+1<m)
                            temp[i+1][j] = (temp[i+1][j]+1)%2;
                        if(j-1>=0)
                            temp[i][j-1] = (temp[i][j-1]+1)%2;
                        if(j+1<n)
                            temp[i][j+1] = (temp[i][j+1]+1)%2;

                        // check if we have visited this position
                        mask = 0;
                        for(int k{0}; k<m; k++)
                        {
                            for(int l{0}; l<n; l++)
                            {
                                if(temp[k][l] == 1)
                                {
                                    mask |= 1<<(k*m+l);
                                }
                            }
                        }

                        if(visited[mask] == false)
                        {
                            visited[mask] = true;
                            pos.push(temp);
                        }
                    }
                }
            }
            
            
            steps++;
        }
        
        return -1;
        
    }
};
