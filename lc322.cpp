class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        
        int n = coins.size();
        int i = 0, j=0;
        vector<int> nums(amount+1, amount+1);
        
        for(i=0; i<n; i++)
        {
            if(coins[i] <= amount)
                nums[coins[i]] = 1;
        }
        
        for(i=1; i<=amount; i++)
        {
            if(nums[i] == 1)
                continue;
            
            for(j =0; j<n; j++)
            {
                if(i - coins[j] > 0)
                {
                    nums[i] = min(nums[i], nums[i-coins[j]]+1);
                }
            }
        }
        
        if(nums[amount] == amount+1)
            return -1;
        else
            return nums[amount];
        
    }
};
