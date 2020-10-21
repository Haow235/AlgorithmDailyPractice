class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // if(amount == 0)
        //     return 0;
        
        int n = coins.size();
        
        vector<int> nums(amount+1, 0);
        
        nums[0] = 1;
        
        for(int j(0); j<n; j++)
        {
            for(int i(coins[j]); i<=amount; i++)
            {
                nums[i] += nums[i-coins[j]];
            }
        }
        
        return nums[amount];
        
    }
};
