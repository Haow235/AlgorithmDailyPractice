class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> rooms;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lh, const vector<int>& rh){
            return lh[0] < rh[0];
        });
        
        int j = 0;
        
        for(auto& i: intervals)
        {
            for(j = 0; j<rooms.size(); j++)
            {
                if(rooms[j]<=i[0])
                {
                    rooms[j] = i[1];
                    break;
                }
            }
            
            if(j == rooms.size())
            {
                rooms.push_back(i[1]);
            }
        }
        
        return rooms.size();
        
    }
};
