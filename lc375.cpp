class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        return getMoneyAmountUtil(1, n, memo);
        
    }
    
private:
    int getMoneyAmountUtil(int lb, int up, vector<vector<int>>& memo)
    {
        if(lb >= up)
            return 0;
        
        if(up - lb < 3)
            return (up + lb)/2;
        
        if(memo[lb][up] != -1)
            return memo[lb][up];
        
        int best = INT_MAX;
        for(int i{lb}; i<=up; i++)
        {
            best = min(best, i+max(getMoneyAmountUtil(lb, i-1, memo), getMoneyAmountUtil(i+1, up, memo)));
        }
        
        memo[lb][up] = best;
        
        return best;
        
    }
};
