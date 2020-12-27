class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int maxleft = 0, minleft = 0, right = 0;
        int maxcount = 0, mincount = 0;
        
        unordered_map<int, int> maxmap;
        unordered_map<int, int> minmap;
        
        int re = 0;
        
        while(right<A.size())
        {
            maxmap[A[right]]++;
            minmap[A[right]]++;
            if(maxmap[A[right]] == 1)
            {
                maxcount++;
            }
            if(minmap[A[right]] == 1)
            {
                mincount++;
            }
            
            while(maxcount>=K)
            {
                maxmap[A[maxleft]]--;
                if(maxmap[A[maxleft]] == 0)
                    maxcount--;
                
                maxleft++;
            }
            while(mincount>K)
            {
                minmap[A[minleft]]--;
                if(minmap[A[minleft]] == 0)
                    mincount--;
                
                minleft++;
            }
            
            re += maxleft-minleft;
            
            right++;
        }
        
        return re;
    }
};
