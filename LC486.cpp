class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return true;
        
        vector<vector<int>> play1(n, vector<int>(n, 0));
        vector<vector<int>> play2(n, vector<int>(n, 0));
        
        for(int i{0}; i<n; i++)
        {
            play1[i][i] = nums[i];
            play2[i][i] = -nums[i];
        }
        
        for(int d{1}; d<n; d++)
        {
            for(int i{0}; i+d<n; i++)
            {
                // get the max score play1 can get from i to i+d
                int tempmax = INT_MIN;
                play1[i][i+d] = max(play2[i][i+d-1]+nums[i+d], play2[i+1][i+d]+nums[i]);
                play2[i][i+d] = min(play1[i][i+d-1]-nums[i+d], play1[i+1][i+d]-nums[i]);
            }
        }
        
        return play1[0][n-1]>=0;
    }
};
