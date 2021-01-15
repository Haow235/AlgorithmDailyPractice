class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
//         int count = 0;
        
//         for(auto a:arr)
//         {
//             if(a == 0)
//                 count++;
//         }
        
//         if(count == 0)
//             return true;
        
        queue<int> positions;
        positions.push(start);
        
        vector<bool> visited(n, false);
        
        while(!positions.empty())
        {
            int curp = positions.front();
            positions.pop();
            
            if(visited[curp])
                continue;
            
            visited[curp] = true;
            
            if(arr[curp] == 0)
            {
                // count--;
                // if(count == 0)
                return true;
            }
            else
            {
                if(curp + arr[curp] < n)
                {
                    positions.push(curp + arr[curp]);
                }
                if(curp - arr[curp] >= 0)
                {
                    positions.push(curp - arr[curp]);
                }
            }
        }
        
        return false;
        
    }
};
