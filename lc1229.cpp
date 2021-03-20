class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end(), [](const vector<int>& lh, const vector<int>& rh){
            return lh[0] < rh[0];
        });
        
        sort(slots2.begin(), slots2.end(), [](const vector<int>& lh, const vector<int>& rh){
            return lh[0] < rh[0];
        });
        
        int n = slots1.size(), m = slots2.size();
        int i = 0, j=0;
        while(i<n && j<m)
        {
            if(slots1[i][1] <= slots2[j][0])
            {
                i++;
            }
            else if(slots1[i][0] >= slots2[j][1])
            {
                j++;
            }
            else
            {
                int overlap = min(slots1[i][1], slots2[j][1]) - max(slots1[i][0], slots2[j][0]);
                if(overlap >= duration)
                {
                    int temp = max(slots1[i][0], slots2[j][0]);
                    return vector<int>{temp, temp+duration};
                }
                
                if(slots1[i][1] < slots2[j][1])
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }
        
        return {};
    }
};
