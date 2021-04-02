class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        
        if(n < m*k)
            return -1;
        
        int l = bloomDay[0], r = 0;
        for(auto i{0}; i<n; i++)
        {
            l = min(l, bloomDay[i]);
            r = max(r, bloomDay[i]);
        }
        
        int cnt = 0;
        int mid;
        int re;
        
        if(l == r)
            return l;
        
        while(l<r)
        {
            int mid = (l+r)/2;
            
            if(ifpossible(bloomDay, m, k, mid))
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        
        return l;
        
    }
    
private:
    bool ifpossible(vector<int> b, int m, int k, int mid)
    {
        int cnt = 0;
        int ct = 0;
        int i = 0;
        while(i<b.size())
        {
            ct = 0;
            while(i<b.size() && b[i] <= mid)
            {
                ct++;                
                
                if(ct == k)
                {
                    cnt++;                    
                    break;
                }
                
                i++;
            }
            
            i++;
        }
        
        if(cnt >= m)
            return true;
        
        return false;
    }
};
