class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // binary find its speed to eat the banana
        int n = piles.size();
        
        int maxp=0, minp = 1;
        for(auto i{0}; i<n; i++)
        {
            maxp = max(maxp, piles[i]);
            // minp = min(minp, piles[i]);
        }
        
        if(n == h)
        {
            return maxp;
        }
        
        
        int cnt = 0;
        int mid = 0;
        int re = 0;
        while(minp <= maxp)
        {
            cnt = 0;
            mid = (minp+maxp)/2;
            
            for(auto i{0}; i<n; i++)
            {
                cnt += (piles[i]/mid);
                cnt += (piles[i]%mid==0?0:1);
            }
            
            if(cnt <= h)
            {
                re = mid;
                maxp = mid-1;
            }
            else
            {
                minp = mid+1;
            }
            
        }
        
        return re;
    }
};
