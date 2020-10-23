class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        
        if(n == 1)
            return stones[0];
        
        unordered_set<int> sums;
        sums.insert(stones[0]);
        sums.insert(-stones[0]);
        
        for(int i{1}; i<n; i++)
        {
            unordered_set<int> temp;
            for(int s:sums)
            {
                temp.insert(s-stones[i]);
                temp.insert(s + stones[i]);
            }
            swap(temp, sums);
        }
        
        int minv = INT_MAX;
        for(int s:sums)
        {
            if(s>=0 && s<minv)
                minv = s;
        }
        
        return minv;
        
    }
};
