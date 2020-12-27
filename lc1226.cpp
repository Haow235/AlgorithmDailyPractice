class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> re;
        if(n == 0 || n<k)
            return re;
        
        if(k == 1)
            return nums;
        
        int i=0;
        deque<pair<int, int>> maxwindow; // index, value
        
        // init deque
        int tempmax = nums[0];
        int maxindex = 0;
        // maxwindow.emplace_back(0, nums[0]);
        for(i=1; i<k;i++)
        {
            if(nums[i] > tempmax)
            {
                tempmax = max(tempmax, nums[i]);
                maxindex = i;
            }
            
            // maxwindow.emplace_back(i, nums[i]);
        }
        
        maxwindow.emplace_back(maxindex, tempmax);
        
//         while(maxwindow.front().second < tempmax)
//         {
//             maxwindow.pop_front();
//         }
        
        for(i=maxindex+1; i<k; i++)
        {
            while(maxwindow.size() && maxwindow.back().second<nums[i])
            {
                maxwindow.pop_back();
            }
            
            maxwindow.emplace_back(i, nums[i]);
        }
        
        re.push_back(maxwindow.front().second);
        
        //go through the nums and build our re
        for(i=k; i<n; i++)
        {
            // first pop the element that outside of the window
            if(maxwindow.front().first <= i-k)
                maxwindow.pop_front();
            
            // pop the element from back if its value is less than the current value
            while(maxwindow.size() && maxwindow.back().second<nums[i])
            {
                maxwindow.pop_back();
            }
            
            // push the current the element into the queue
            maxwindow.emplace_back(i, nums[i]);
            
            re.push_back(maxwindow.front().second);
        }
        
        return re;
        
    }
};
