class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        // edge case
        if(m == n && (m==0 || word1 == word2))
            return 0;
        if(m == 0)
            return n;
        if(n == 0)
            return m;
        
        //memory dp[i][j] to keep track of the operations need to convert word1 from i to word2 from j
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return minDistanceUtil(word1, 0, word2, 0, dp);
    }
    
private:
  int minDistanceUtil(string& word1, int p1, string& word2, int p2, vector<vector<int>>& dp)
  {
      // base case
      if(p2 == word2.size())
      {
          return word1.size()-p1;
      }
      
      // if we have calculated the minimum operation that start from p1 and p2
      if(dp[p1][p2] != -1)
          return dp[p1][p2];
      
      // else, we have at most three choice at this state
      
      // insert a new character
      int re = minDistanceUtil(word1, p1, word2, p2+1, dp) + 1;
      if(p1 != word1.size())
      {
          if(word1[p1] == word2[p2])
          {
              re = min(re, minDistanceUtil(word1, p1+1, word2, p2+1, dp));
          }
          else
          {
              re = min(re, 1 + minDistanceUtil(word1, p1+1, word2, p2+1, dp));
          }
          
          re = min(re, 1+ minDistanceUtil(word1, p1+1, word2, p2, dp));
      }
      
      dp[p1][p2] = re;
      return re;
  }
};
