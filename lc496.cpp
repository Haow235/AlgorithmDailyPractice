class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> info;
        
        vector<int> re(nums1.size());
        
        int temp;
        
        for(int i{0}; i<nums2.size(); i++)
        {
            while(!info.empty() && nums2[i] > info.top())
            {
                temp = info.top();
                info.pop();
                next_greater[temp] = nums2[i];
            }
            
            info.push(nums2[i]);
        }
        
        while(!info.empty())
        {
            temp = info.top();
            info.pop();
            next_greater[temp] = -1;
        }
        
        for(int i{0}; i<nums1.size(); i++)
        {
            re[i] = next_greater[nums1[i]];
        }
        
        return re;
        
    }
};
