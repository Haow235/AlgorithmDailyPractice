class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n=nums.size();
        for(int i{0}; i<n; i++)
        {
            sum+=nums[i];
        }
        
        if(sum%2)
            return false;
        
        sum /= 2;
        
        vector<vector<int>> info(n, vector<int>(sum+1, -1)); 
        
        return canPartitionUtil(nums, info, sum, 0);
    }
    
private:
    bool canPartitionUtil(vector<int>& nums, vector<vector<int>>& info, int cursum, int p)
    {
        if(p == nums.size())
            return false;
        
        if(info[p][cursum] != -1)
            return info[p][cursum]==0?true:false;
        
        int tempsum = cursum - nums[p];
        if(tempsum==0)
            return true;
        
        bool re = false;
        if(tempsum>0)
            re = canPartitionUtil(nums, info, tempsum, p+1);
            
        re = (re || canPartitionUtil(nums, info, cursum, p+1));
        
        info[p][cursum] = (re==true?0:1);
        
        return re;   
    }
    
};