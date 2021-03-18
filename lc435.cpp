class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return 0;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lh, const vector<int>& rh){
           return lh[1] < rh[1]; 
        });
        
        int re = 0;
        int preend = intervals[0][1];
        for(auto i{1}; i<intervals.size(); i++)
        {
            if(intervals[i][0] < preend)
            {
                re++;
            }
            else
            {
                preend = intervals[i][1];
            }
        }
        
        return re;
    }
};
