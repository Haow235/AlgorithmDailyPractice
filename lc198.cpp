/*
use dp[i] to represent the max money we can get from array start at index i
so dp[i] = max(dp[i+2]+nums[i], dp[i+1])
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        vector<int> dp(n+1, 0);
        dp[n-1] = nums[n-1];
        for(int i{n-2}; i>=0; i--)
        {
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }
        
        return dp[0];
        
    }
};
