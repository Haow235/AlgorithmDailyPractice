class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0)
            return 0;
        
        unordered_map<int, int> info; // sum => num
        info[nums[0]] = 1;
        info[-nums[0]] += 1;
        
        for(int i{1}; i<nums.size(); i++)
        {
            unordered_map<int, int> temp;
            for(auto it=info.begin(); it!=info.end(); it++)
            {      
                temp[(it->first)+nums[i]] += it->second;
                                                  
                temp[(it->first)-nums[i]] += it->second;
            }
            
            swap(info, temp);
        }
        
        return info[S];
        
    }
};
