class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        if(n<4)
            return false;
        
        int total_length = 0;
        for(int num: nums)
        {
            total_length+=num;
        }
        
        if(total_length%4)
            return false;
        
        int length = total_length/4;
        
        int mask = 0;
        
        map<int, bool> info;
        
        return makesquareUtil(nums, mask, 0, length, info);
    }
    
private:
    bool makesquareUtil(vector<int>& nums, int mask, int sides, int length, map< int, bool>& info)
    {
        
        if(info.find(mask) != info.end())
            return info[mask];
        
        int total = 0;
        for(int i{0}; i<nums.size(); i++)
        {
            if((mask & 1<<i))
            {
                total += nums[i];
            }
        }
        
        if(total != 0 && total%length == 0)
            sides++;
        
        if(sides == 3)
            return true;
        
        int rm = total%length;
        bool re = false;
        for(int i{0}; i<nums.size(); i++)
        {
            if(!(mask & 1<<i) && nums[i]+rm<=length)
            {
                // mask = mask|(1<<i);
                re = makesquareUtil(nums, mask|(1<<i), sides, length, info);
                if(re)
                {
                    return true;
                }
                // mask = mask^(1<<i);
            }
        }
        
        info[mask] = re;
        return re;
    }
};
