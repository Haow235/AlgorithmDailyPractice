class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> re(n, 0);
        stack<int> info; // the index of the num
        
        for(int i{0}; i<n; i++)
        {
            while(!info.empty() && nums[i] > nums[info.top()])
            {
                re[info.top()] = nums[i];
                info.pop();
            }
            
            info.push(i);
        }
        
        // if(!info.empty())
        for(int i{0}; i<n; i++)
        {
            while(!info.empty() && nums[i] > nums[info.top()])
            {
                re[info.top()] = nums[i];
                info.pop();
            }
            
            if(info.empty())
                break;
        }
        
        while(!info.empty())
        {
            re[info.top()] = -1;
            info.pop();
        }
        
        return re;
        
    }
};
