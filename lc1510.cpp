class Solution {
public:
    bool winnerSquareGame(int n) {
        unordered_map<int, bool> win;
        // unordered_map<int, bool> b;
        
        return winnerSquareGameUtil(n, win);
    }
    
private:
    bool winnerSquareGameUtil(int n, unordered_map<int, bool>& win)
    {
        if(n == 0)
            return false;
        
        if(win.find(n) != win.end())
            return win[n];
        
        bool re = false;
        int i = sqrt(n);
        for(; i>0; i--)
        {
            re = winnerSquareGameUtil(n-i*i, win);
            if(re == false)
            {
                win[n] = true;
                return true;
            
            }
        }
        
        win[n]=false;
        
        return false;
    }
};
