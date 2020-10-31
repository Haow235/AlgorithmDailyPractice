class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j=numbers.size()-1;
        int cursum;
        
        while(i<j)
        {
            cursum = numbers[i] + numbers[j];
            if(cursum == target)
                return {i+1, j+1};
            else if(cursum < target)
            {
                i++;
            }
            else
                j--;
        }
        
        return {};
        
    }
};
