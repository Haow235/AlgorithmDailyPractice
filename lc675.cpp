class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        
        // Store all the trees and sort in ascending order
        vector<vector<int>> trees;
        for(auto i{0}; i<m; i++)
        {
            for(auto j{0}; j<n; j++)
            {
                if(forest[i][j] > 1)
                {
                    trees.push_back({forest[i][j], i, j});
                }
            }
        }
        
        sort(trees.begin(), trees.end());
        
        // find the number of minium steps from trees[i] to trees[j]
        int steps = 0;
        
        int sr=0, sc=0;
        int tr, tc;
        
        for(auto i{0}; i<trees.size(); i++)
        {
            tr = trees[i][1];
            tc = trees[i][2];
            
            int step = findstep(forest, sr, sc, tr, tc);
            if(step == -1)
                return -1;
            
            steps += step;
            
            sr = tr;
            sc = tc;
        }
        
        return steps;
        
    }
    
private:
    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int findstep(vector<vector<int>>& forest, int sr, int sc, int tr, int tc)
    {
        int m = forest.size(), n = forest[0].size();
        vector<vector<char>> visited(m, vector<char>(n, 0));
        
        queue<pair<int, int>> pos;
        pos.push({sr, sc});
        visited[sr][sc] = 0;
        
        int step = 0;
        
        while(!pos.empty())
        {
            int size = pos.size();
            
            while(size-->0)
            {
                pair<int, int> cur = pos.front();
                pos.pop();
                
                if(cur.first == tr && cur.second == tc)
                {
                    return step;
                }
                
                for(int i{0}; i<4; i++)
                {
                    int nr = cur.first + dirs[i][0];
                    int nc = cur.second + dirs[i][1];
                    
                    if(nr >=0 && nr<m && nc >= 0 && nc < n && visited[nr][nc] == 0 && forest[nr][nc] != 0)
                    {
                        pos.push({nr, nc});
                        visited[nr][nc] = 1;
                    }
                }
            }
            
            step++;
        }
        
        return -1;
    }
};
