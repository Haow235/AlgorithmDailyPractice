class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        // use dp[i][mask] to represent the maximum number of student that from row i with i-1 row mask
        int n = seats.size();
        int m = seats[0].size();
        
        vector<vector<int>> dp(n, vector<int>(1<<m, -1));
        
        return maxStudentsUtil(seats, dp, 0, 0);
        
    }
    
private:
    int maxStudentsUtil(vector<vector<char>>& seats, vector<vector<int>>& dp, int currow, int mask)
    {
        //base case
        if(currow == seats.size())
            return 0;
        
        // have calculated this situation
        if(dp[currow][mask] != -1)
            return dp[currow][mask];
        
        // we don't put any student in this row
        int re = maxStudentsUtil(seats, dp, currow+1, 0);
        int curmask = 0;
        int m = seats[0].size();
        
        // find valid position
        int valid = 0;
        for(int i{0}; i<m; i++)
        {
            if(seats[currow][i] == '.')
            {
                valid |= (1<<i);
            }
        }
        
        
        // find all valid position in this row
        for(; curmask<(1<<m); curmask++)
        {
            // if valid position and no student are put in adjacent seat and can't see the answer of former student
            if((curmask & valid) == curmask && (curmask & (curmask>>1)) == 0 && (curmask & (mask<<1)) == 0 && (curmask & (mask>>1)) == 0)
            {
                re = max(re, getbits(curmask) + maxStudentsUtil(seats, dp, currow+1, curmask));
            }
        }
        
        dp[currow][mask] = re;
        return re;
        
    }
    
    int getbits(int mask)
    {
        int re = 0;
        while(mask)
        {
            if(mask%2)
                re++;
            
            mask = mask>>1;
        }
        
        return re;
    }
};
