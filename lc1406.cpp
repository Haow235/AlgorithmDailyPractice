class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if(n == 0)
            return "Tie";
        
//         // vector<int> diff(n, );
//         unordered_map<int, int> diff;
//         diff[n] = 0;
        
//         stoneGameIIIUtil(stoneValue, 0, diff);
        
        vector<int> diff(n+1, INT_MIN);
        diff[n] = 0;
        int cursum;
        for(int i{n-1}; i>=0; i--)
        {
            cursum = 0;
            for(int k{0}; k<3 && i+k<n; k++)
            {
                cursum += stoneValue[i+k];
                diff[i] = max(cursum - diff[i+k+1], diff[i]);
            }
        }
        
        if(diff[0] < 0)
            return "Bob";
        else if(diff[0] == 0)
            return "Tie";
        else
            return "Alice";
    }
    
// private:
//     int stoneGameIIIUtil(vector<int>& stoneValue, int p, unordered_map<int, int>& diff)
//     {
//         if(diff.find(p) != diff.end())
//             return diff[p];
        
//         int optima = INT_MIN;
//         int cursum = 0;
//         for(int i{0}; i<3 && i+p<stoneValue.size(); i++)
//         {
//             cursum += stoneValue[p+i];
//             // cursum += stoneGameIIIUtil(stoneValue, p+i+1, diff);
//             optima = max(cursum - stoneGameIIIUtil(stoneValue, p+i+1, diff), optima);
//         }
        
//         diff[p] = optima;
//         return optima;
//     }
};
