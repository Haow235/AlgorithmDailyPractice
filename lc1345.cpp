class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> visited(n, false);
        
        unordered_map<int, vector<int>> same_index;
        
        for(auto i{0}; i<n; i++)
        {
            same_index[arr[i]].push_back(i);
        }
        
        queue<int> pos;
        pos.push(0);
        visited[0] = true;
        
        int steps = 0;
        while(!pos.empty())
        {
            int size = pos.size();
            while(size-->0)
            {
                int curp = pos.front();
                pos.pop();
                
                if(curp == n-1)
                    return steps;
                
                if(curp-1 >= 0 && visited[curp-1] == false)
                {
                    pos.push(curp-1);
                    visited[curp-1] = true;
                }
                if(visited[curp+1] == false)
                {
                    pos.push(curp+1);
                    visited[curp+1] = true;
                }
                for(int i=same_index[arr[curp]].size()-1; i>=0; i--)
                {
                    if(visited[same_index[arr[curp]][i]] == false)
                    {
                        pos.push(same_index[arr[curp]][i]);
                        visited[same_index[arr[curp]][i]] = true;
                    }
                }
                
                same_index[arr[curp]].clear();
            }
            
            steps++;
        }
        
        return -1;
    }
};
