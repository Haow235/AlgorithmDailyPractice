class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        int m = dependencies.size();
        if(m == 0)
            return n/k + (n%k?1:0);
        
        //represents the prerequest for each class
        vector<int> prereq(n+1, 0);
        for(int i{0}; i<m; i++)
        {
            prereq[dependencies[i][1]-1] |= (1<<(dependencies[i][0]-1));
        }
        
        // use dp[mask] to represent the mininum semester need to take for all couses that represented by mask
        vector<int> dp(1<<n, n);
        dp[0] = 0;
        
        // for each mask from 0 to 1<<n, find the semesters needed.
        int candidate = 0;
        for(int mask{0}; mask<(1<<n); mask++)
        {
            // find all candidate courses we can take for the current semester
            candidate = 0;
            for(int j{0}; j<n; j++)
            {
                // we can take a couse only all its prerequest has been taken, that is prereq[j] is a subset of current mask
                if((prereq[j] & mask) == prereq[j])
                {
                    candidate |= (1<<j); // this will also include the couses we have taken in the former semester, so we need to move those courses later
                }
            }
            
            // cout<<'i' << mask << 'c'<<candidate<< endl;
            
            // remove all courses have been taken before this semester
            candidate &= (~mask); // candidate now is a superset of mask
            
            // enumerate all possible of couses combination that we can take this semester
            for(int c{candidate}; c>0; c = (c-1)&candidate)
            {
                // we can only take at most k courses
                if(findsetbits(c) <= k)
                {
                    dp[mask|c] = min(dp[mask|c], dp[mask]+1);
                    // cout<<(mask|c) << ' '<<dp[mask|c]<<endl;
                }
            }
        }
        
        return dp[(1<<n)-1];
        
    }
    
private:
    int findsetbits(int c)
    {
        int re = 0;
        while(c)
        {
            re += (c&1);
            c = c>>1;
        }
        
        return re;
    }
};
