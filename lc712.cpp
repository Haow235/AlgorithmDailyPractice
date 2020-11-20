class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        vector<vector<int>> del_sum(n+1, vector<int>(m+1, 0));
        
        for(int i{1}; i<=n; i++)
        {
            del_sum[i][0] = del_sum[i-1][0] + s1[i-1];
        }
        for(int i{1}; i<=m; i++)
        {
            del_sum[0][i] = del_sum[0][i-1] + s2[i-1];
        }
        
        // build the cost matrix
        for(int i{1}; i<=n; i++)
        {
            for(int j{1}; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1]) // the char of the current position are equal
                {
                    del_sum[i][j] = del_sum[i-1][j-1];
                }
                else
                {
                    del_sum[i][j] = min(del_sum[i-1][j] + s1[i-1], del_sum[i][j-1] + s2[j-1]);
                }
            }
        }
        
        return del_sum[n][m];
        
    }
};
