/*
we can use dp[i][j] to represent the length of the longest subsequence for text1 from i and for text2 from j.
so dp[i][j] = max(dp[i+1][j], dp[i][j+1], dp[i+1][j+1]+1)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m=text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i{n-1}; i>=0; i--)
        {
            for(int j{m-1}; j>=0; j--)
            {
                if(text1[i] == text2[j])
                {
                    dp[i][j] = dp[i+1][j+1] + 1;
                }
                
                else
                {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
        
    }
};
