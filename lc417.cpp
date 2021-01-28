class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0)
            return vector<vector<int>>();
        int n = matrix[0].size();
        if(n == 0)
            return vector<vector<int>>();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        queue<pair<int, int>> pos;
        for(auto i{0}; i<n; i++)
        {
            pos.push({0, i});
            pacific[0][i] = true;
        }
        for(auto i{1}; i<m; i++)
        {
            pacific[i][0] = true;
            pos.push({i, 0});
        }
        
        while(!pos.empty())
        {
            pair<int, int> cur = pos.front();
            pos.pop();
            
            for(auto i{0}; i<4; i++)
            {
                int nx = cur.first + dir[i][0];
                int ny = cur.second + dir[i][1];
                if(nx >= 0 && nx<m && ny>=0 && ny<n && pacific[nx][ny] == false && matrix[nx][ny] >= matrix[cur.first][cur.second])
                {
                    pacific[nx][ny] = true;
                    pos.push({nx, ny});
                }
            }
        }
        
//         for(auto i{0}; i<m; i++)
//         {
//             for(auto j{0}; j<n; j++)
//             {
//                 cout<<pacific[i][j]<<' ';
//             }
//             cout<<endl;
//         }
        
        
        for(auto i{0}; i<n; i++)
        {
            pos.push({m-1, i});
            atlantic[m-1][i] = true;
        }
        for(auto i{0}; i<m-1; i++)
        {
            pos.push({i, n-1});
            atlantic[i][n-1] = true;
        }
        
        while(!pos.empty())
        {
            pair<int, int> cur = pos.front();
            pos.pop();
            
            for(auto i{0}; i<4; i++)
            {
                int nx = cur.first + dir[i][0];
                int ny = cur.second + dir[i][1];
                if(nx >= 0 && nx<m && ny>=0 && ny<n && atlantic[nx][ny] == false && matrix[nx][ny] >= matrix[cur.first][cur.second])
                {
                    atlantic[nx][ny] = true;
                    pos.push({nx, ny});
                }
            }
        }
        
//         cout<<"++++++"<<endl;
        
//         for(auto i{0}; i<m; i++)
//         {
//             for(auto j{0}; j<n; j++)
//             {
//                 cout<<atlantic[i][j]<<' ';
//             }
//             cout<<endl;
//         }
        
        vector<vector<int>> re;
        for(auto i{0}; i<m; i++)
        {
            for(auto j{0}; j<n; j++)
            {
                if(atlantic[i][j] && pacific[i][j])
                {
                    re.push_back({i, j});
                }
            }
        }
        
        return re;
        
        
    }
};
