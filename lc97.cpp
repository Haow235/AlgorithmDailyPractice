/*
we can use two dp[i][j] to indicate if s1 end with i and s2 end with j can form s3 interleavingly, and the two dp are used to represent where the last character come from
dp2[i][j] = if dp1[i][j-k] == true and s2(j-k, k) == s3(i+j-k, i+j);
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m= s2.size();
        int l = s3.size();
        
        if(l != m+n)
            return false;
        if(l == 0 && m == 0 && n == 0)
            return true;
        if(m==0)
            return s1==s3;
        if(n == 0)
            return s2 == s3;
        
        vector<vector<int>> dp1(n+1, vector<int>(m+1, -1));
        vector<vector<int>> dp2(n+1, vector<int>(m+1, -1));
        
        return isInterleaveUtil(s1, s2, s3, 0, 0, 0, dp1, dp2, 1) || isInterleaveUtil(s1, s2, s3, 0, 0, 0, dp1, dp2, 2);
        
    }
    
private:
    bool isInterleaveUtil(string& s1, string& s2, string& s3, int p1, int p2, int p3, vector<vector<int>>& dp1, vector<vector<int>>& dp2, int turn)
    {
        if(p3 == s3.size())
            return true;
        
        bool re = false;
        if(turn == 1)
        {
            if(p1 >= s1.size())
                return false;
            
            if(dp1[p1][p2] != -1)
                return dp1[p1][p2];
            
            for(int i{0}; i+p1<s1.size(); i++)
            {
                if(s1[i+p1] == s3[i+p3])
                {
                    re = isInterleaveUtil(s1, s2, s3, p1+i+1, p2, p3+i+1, dp1, dp2, 2);
                    if(re)
                    {
                        dp1[p1][p2] = 1;
                        return true;
                    }
                }
                else
                    break;
            }
            
            dp1[p1][p2] = 0;
            return false;
        }
        else
        {
            if(p2 >= s2.size())
                return false; 
            
            if(dp2[p1][p2] != -1)
                return dp2[p1][p2];
            
            for(int i{0}; i+p2<s2.size(); i++)
            {
                if(s2[i+p2] == s3[i+p3])
                {
                    re = isInterleaveUtil(s1, s2, s3, p1, p2+i+1, p3+i+1, dp1, dp2, 1);
                    if(re)
                    {
                        dp2[p1][p2] = 1;
                        return true;
                    }
                }
                else
                    break;
            }
            
            dp2[p1][p2] = 0;
            return false;
        }
    }
};
