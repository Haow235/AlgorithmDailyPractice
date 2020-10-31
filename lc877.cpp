class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        bool turn = true;  // false - lee, true - Alex
        vector<vector<int>> score_diff(n, vector<int>(n, 0));
        
        int j;
        
        for(int i{0}; i<n; i++)
        {
            score_diff[i][i] = -piles[i];
        }
        
        for(int d{1}; d<n; d++)
        {
            for(int i{0}; i+d<n; i++)
            {
                j = i+d;
                if(turn)
                {
                    // cout<<"Alex"<<endl;
                    score_diff[i][j] = max(score_diff[i][j-1] + piles[j], score_diff[i+1][j] + piles[i]);
                    // cout<<i<<j<<' '<<score_diff[i][j]<<endl;
                }
                else
                {
                    // cout<<"Lee"<<endl;
                    score_diff[i][j] = min(score_diff[i][j-1] - piles[j], score_diff[i+1][j] - piles[i]);
                    // cout<<i<<j<<' '<<score_diff[i][j]<<endl;
                }
            }
            
            turn = !turn;
        }
        
        // cout<<score_diff[0][n-1];
        return score_diff[0][n-1]>0;
        
    }
};
