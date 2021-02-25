class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        /*
            basic idea is:
                1. find the maximum number of bits to represent all the num
                2. because the maximum candidate is 111..111, so we can start from the 
                    highest bit, to check if its possible to get with the num of nums
                3. if its possible, update that bit to one, and check the next bit
        */
        
        int max_num = 0;
        for(auto n: nums)
        {
            max_num = max(max_num, n);
        }
        
        // find the number of bits 
        int n_bits = 0;
        int temp = max_num;
        while(temp)
        {
            n_bits++;
            temp >>= 1;
        }
        
        // start from the highest bits to check if its possible
        int maxre = 0;
        int candidate = 0;
        while(n_bits-->0)
        {
            maxre <<= 1;
            candidate = maxre | 1;
            
            // we check if its possbile to get the candidate with the num
            unordered_set<int> prefixs;
            for(auto num: nums)
            {
                temp = num >> n_bits;
                if(prefixs.find(candidate ^ temp) != prefixs.end())
                {
                    maxre = candidate;
                    break;
                }
                
                prefixs.insert(temp);
            }
        }
        
        return maxre;
    }
};
