class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int correct = pow(10, 9)+7;
        
        vector<int> pows(n, 0);
        pows[0] = 1;
        
        for(auto i{1}; i<n; i++)
        {
            pows[i] = (pows[i-1]<<1)%correct;
        }
        
        sort(nums.begin(), nums.end());
        
        int re = 0;
        int i = 0, j=n-1;
        
        while(i<=j)
        {
            if(nums[i] + nums[j] <= target)
            {
                re = (re + pows[j-i])%correct;
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return re;
        
    }
};
