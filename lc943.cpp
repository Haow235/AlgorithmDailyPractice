class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        if(n == 1)
            return A[0];
        
        int i, j;
        // compute overlap of A[i] and A[j]
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(j != i)
                {
                    overlap[i][j] = findOverlap(A[i], A[j]);
                    // cout<<i<<j<<' ' << overlap[i][j]<<endl;
                }
                
            }
        }
        
        //compute dp[mask][i]
        int mask = 0;
        vector<vector<int>> dp(1<<n, vector<int>(n, 0));
        vector<vector<int>> parent(1<<n, vector<int>(n, -1));
        
        for(; mask<(1<<n); mask++)
        {
            for(i=0; i<n; i++)
            {
                if(mask & (1<<i))
                {
                    int pmask = mask ^ (1<<i);
                    for(j=0; j<n; j++)
                    {
                        if(pmask & (1<<j) )
                        {
                            if(dp[pmask][j] + overlap[j][i] >= dp[mask][i])
                            {
                                dp[mask][i] = dp[pmask][j] + overlap[j][i];
                                parent[mask][i] = j;
                            }
                        }
                    }
                }
            }
        }
        
        // find the max dp[max][i]
        mask = (1<<n) - 1;
        int e = -1;
        int maxl = -1;
        for(i=0; i<n; i++)
        {
            if(dp[mask][i] > maxl)
            {
                maxl = dp[mask][i];
                e = i;
            }
        }
        cout<<maxl<<endl;
        
        string re=A[e];
        int pre = e;
        // cout<<e<<endl;
        
        e = parent[mask][e];
        
        mask = mask ^ (1<<pre);
        
        while(e != -1)
        {
            // cout<<e<<endl;
            // // cout<<parent[mask][e]<<endl;
            // cout<<re<<endl;
            re = A[e].substr(0, A[e].size()-overlap[e][pre]) + re;
            pre = e;
            e = parent[mask][e];
            mask = mask ^ (1<<pre);
        }
        
        return re;
    }
    
private:
    int findOverlap(const string& lh, const string& rh)
    {
        for(int i{0}; i<lh.size(); i++)
        {
            if(lh[i] == rh[0])
            {
                int j = i+1;
                int k = 1;
                while(j<lh.size() && k<rh.size() && lh[j] == rh[k])
                {
                    j++;
                    k++;
                }
                
                if(j == lh.size())
                {
                    return j-i;
                }
            }
        }
        
        return 0;
    }
};
