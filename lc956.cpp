class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        if(n <= 1)
            return 0;
        
        // int l = min(10001, n*1000*2)
        
        vector<vector<bool>> dp(n+1, vector<bool>(10001, false));
        
        dp[0][5000] = true;
        
        vector<vector<int>> ml(n+1, vector<int>(10001, 0));
        
        for(int i{1}; i<=n; i++)
        {
            for(int j{0}; j<10001; j++)
            {
                if(dp[i-1][j])
                {
                    dp[i][j] = true;
                    ml[i][j] = max(ml[i][j], ml[i-1][j]);
                }
                
                if(j - rods[i-1] >= 0 && dp[i-1][j-rods[i-1]])
                {
                    dp[i][j] = true;
                    ml[i][j] = max(ml[i][j], ml[i-1][j-rods[i-1]]+rods[i-1]);
                }
                
                if(j + rods[i-1] < 10001 && dp[i-1][j+rods[i-1]])
                {
                    dp[i][j] = true;
                    ml[i][j] = max(ml[i][j], ml[i-1][j+rods[i-1]]);
                }
            }
        }
        
        return ml[n][5000];
        
    }
};
