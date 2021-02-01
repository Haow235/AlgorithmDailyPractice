class Solution {
public:
    void findSubsets(vector<vector<int>>& re, vector<int>& nums, int ci, vector<int> cv)
    {
        if(ci == nums.size())
            return;
        
        findSubsets(re, nums, ci+1, cv);
        
        cv.push_back(nums[ci]);
        re.push_back(cv);
        
        findSubsets(re, nums, ci+1, cv);
        
        return;
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> re{{}};
        vector<int> cv{};
        findSubsets(re, nums, 0, cv);
        
        return re;
    }
};
