class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size();
        if(n <= 1)
            return false;
        
        int s = 0;
        for(int i{0}; i<n; i++)
            s+=A[i];
        
        int K = n/2;
        // bitset<150001> info[K] = {{1}};
        vector<unordered_set<int>> info(K+1);
        info[0].insert(0);
        
        for(int a: A)
        {
            for(int i{K}; i>0; i--)
            {
                // info[i] |= info[i-1] << a;
                for(auto it:info[i-1])
                {
                    info[i].insert(it+a);
                }
            }
        }
        
        for(int i{1}; i<=K; i++)
        {
            if((s*i)%n == 0 && info[i].find(s*i/n) != info[i].end())
                return true;
        }
        
        return false;
    }
};

// #include <bitset>  

// class Solution {
// public:
//     bool splitArraySameAverage(vector<int>& A) {        
//         int N = A.size(), S = 0;
//         for (int a : A) S += a;
//         bitset<300001> p[N] = {1};
//         for (int a : A)
//             for (int n = N - 2; n >= 0; n--)
//                 p[n+1] |= p[n] << a;
//         for (int n = 1; n < N; n++)
//             if (S*n%N == 0  &&  p[n][S*n/N])
//                 return true;
//         return false;
//     }
// };

