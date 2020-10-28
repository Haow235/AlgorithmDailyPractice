class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int s = (maxChoosableInteger * (maxChoosableInteger + 1))/2;
        if(s < desiredTotal)
            return false;
        
        int mask = 0;
        unordered_map<int, bool> info; // mask -> value
        
        return canIWinUtil(maxChoosableInteger, desiredTotal, mask, 0, info);
    }
    
private:
    bool canIWinUtil(int maxChoosableInteger, int desiredTotal, int mask, int cursum, unordered_map<int, bool>& info)
    {
        if(info.find(mask) != info.end())
            return info[mask];
        
        int i = maxChoosableInteger;
        while(i> 0 && (mask&(1<<i)))
        {
            i--;
        }
        
        if(i != 0 && i+cursum >= desiredTotal)
        {
            info[mask] = true;
            return true;
        }
        
        bool re = false;
        while(i>0)
        {
            if(!(mask&(1<<i)))
            {
                re = canIWinUtil(maxChoosableInteger, desiredTotal, mask|(1<<i), cursum+i, info);
                if(re == false)
                {
                    info[mask] = true;
                    return true;
                }
                    // return true;
            }
            
            i--;
        }
        
        info[mask] = false;
        return false;
    }
};
