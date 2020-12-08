class Solution {
public:
    int calculate(string s) {
        int p = 0;
        return calculateUtil(s, p);
    }
    
private:
    int calculateUtil(string& s, int& p)
    {
        char sign = '+';
        int re = 0;
        
        while(p<s.size())
        {
            if(s[p] == '+')
                sign = '+';
            else if(s[p] == '-')
                sign = '-';
            else if(s[p] == '(')
            {
                p += 1;
                int curnum = calculateUtil(s, p);
                if(sign == '+')
                {
                    re += curnum;
                }
                else
                {
                    re -= curnum;
                }
            }
            else if(s[p] == ')')
            {
                // p+=1;
                return re;
            }
            else if(isdigit(s[p]))
            {
                int curnum = 0;
                while(p<s.size() && isdigit(s[p]))
                {
                    
                    curnum = curnum*10 + (s[p]-'0');
                    p++;
                }
                p--;
                
                if(sign == '+')
                {
                    re += curnum;
                }
                else
                {
                    re -= curnum;
                }
            }
            
            p++;
                
        }
        
        return re;
    }
};
