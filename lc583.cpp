/*
we can use dynamic programming for this problem, that is, our goal is to find the minimum number of steps to make word1 and word2 equal, it equal to find the longest common substring from word1 and word2, let's say k, then the steps we need would be n1-k+n2-k
so we can use dp[i][j] to represent the longest common subarray length of word1 form 0 to i, and for word2 from 0 to j, then dp[i][j] = dp[i-1][j-1]+1 if word1[i] == word2[j], or dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
we padding an additional row and column for computation convenient
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(), n2=word2.size();
        
        // edge case
        if(n1 == 0)
            return n2;
        if(n2 == 0)
            return n1;
        
        // dynamic programming
        vector<vector<int>> min_steps(n1+1, vector<int>(n2+1, 0));
        for(int i{1}; i<=n1; i++)
        {
            for(int j{1}; j<=n2; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    min_steps[i][j] = min_steps[i-1][j-1]+1;
                    
                }
                else
                {
                    min_steps[i][j] = max(min_steps[i-1][j], min_steps[i][j-1]);
                }
            }
        }
        
        return n1+n2-min_steps[n1][n2]*2;
    }
};
