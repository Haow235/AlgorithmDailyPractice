struct cmp
{
    bool operator()(const pair<int, int>& lh, const pair<int, int>& rh)
    {
        return lh.second < rh.second;
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n);
        dp[n-1] = nums[n-1];
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> maxvalue;
        maxvalue.push({n-1, dp[n-1]});
        
        for(int i{n-2}; i>=0; i--)
        {
            while(maxvalue.top().first > i+k)
            {
                maxvalue.pop();
            }
            
            dp[i] = nums[i] + maxvalue.top().second;
            maxvalue.push({i, dp[i]});
        }
        
        return dp[0];
        
    }
};
