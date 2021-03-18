class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& lh, const vector<int>& rh){
            // if(lh[0] == rh[0])
            //     return lh[1] < rh[1];
            
            return lh[1] < rh[1];
        });
        
        int re = 0;
        
        for(auto i{0}; i<points.size(); i++)
        {
            int curp = points[i][1];
            
            i++;
            while(i<points.size() && points[i][0] <= curp)
            {
                i++;
            }
            
            i--;
            re++;
        }
        
        return re;
        
    }
};
