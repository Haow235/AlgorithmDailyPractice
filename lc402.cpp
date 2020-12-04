class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(num.size() == k)
            return "0";
        
        // Iteratively find the best choice for each position
        stack<char> reserve;
        // reserve.push(num[0]);
        
        int curmin;
        int p = 0;
        int nextk, nextp;
        
        while(k)
        {
            if(k == n-p)
                break;
            
            reserve.push(num[p]);
            
            nextk = k;
            nextp = p + 1;
            
            for(int i{1}; i<=k; i++)
            {
                if(num[p+i] < reserve.top())
                {
                    reserve.pop();
                    reserve.push(num[p+i]);
                    nextk = k-i;
                    nextp = p + i + 1;
                }
            }
            
            p = nextp;
            k = nextk;
        }
        
        if(k ==0)
        {
            while(p < n)
            {
                reserve.push(num[p++]);
            }
        }
        
        string re = "";
        while(!reserve.empty())
        {
            re = reserve.top() + re;
            reserve.pop();
        }
        
        int i=0;
        for(; i<re.size(); i++)
        {
            if(re[i] != '0')
                break;
        }
        
        if(i == re.size())
            return "0";
        
        return re.substr(i);
        
    }
};
