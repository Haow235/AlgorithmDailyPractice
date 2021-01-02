/*
1. overflow? no
2. edge case: all negative => biggest one
              start with some negative number, followed by some positive number
              
*/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        // use dp[i] to represent the maximum we can get start with index i and include i.
        int n= nums.size();
        int re = INT_MIN;
        deque<int> maxinfo;
        vector<int> dp(n, 0);
        for(int i(n-1); i>=0; i--)
        {
            dp[i] = nums[i];
            // for(int j{1}; j<=k; j++)
            // {
            //     if(i+j<n)
            //         dp[i] = max(dp[i], nums[i] + dp[i+j]);
            //     else 
            //         break;
            // }
            if(maxinfo.front() - i > k)
            {
                maxinfo.pop_front();
            }
            
            if(maxinfo.size())
            {
                dp[i] = max(dp[i], dp[i]+dp[maxinfo.front()]);
            }
            while(maxinfo.size() != 0 && dp[maxinfo.back()] < dp[i])
            {
                maxinfo.pop_back();
            }
            maxinfo.push_back(i);
                
            
            re = max(re, dp[i]);
        }
        
        return re;
        
    }
};
