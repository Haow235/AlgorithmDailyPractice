/*

3+5/2*3 => 3 + 2*3

two stack, one for the operators and one for the integers:
    if we meet + or -, if the operator stack is not none, we calculate it, push the result back
    if we meet * or /, only if the operator stack top is one of the * or /, then we calculated it, push the result back

*/

int calc(int lh, int rh, char op)
{
    if(op == '+')
    {
        return lh+rh;
    }
    else if(op == '-')
    {
        return lh - rh;
    }
    else if(op == '*')
    {
        return lh*rh;
    }
    else
    {
        return lh/rh;
    }
    
    return 0;
}

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        
        stack<long> nums;
        stack<int> opers;
        
        long pre = 0;
        
        for(int i{0}; i<=n; i++)
        {
            if(i == n || s[i] == '+' || s[i] == '-')
            {
                while(!opers.empty())
                {
                    pre = calc(nums.top(), pre, opers.top());
                    
                    opers.pop();
                    nums.pop();
                    
                    // nums.push(pre);
                }
                
                nums.push(pre);
                pre = 0;
                if(i!=n)
                    opers.push(s[i]);
            }
            else if(s[i] == '/' || s[i] == '*')
            {
                if(!opers.empty() && (opers.top() == '/' || opers.top() == '*'))
                {
                    pre = calc(nums.top(), pre, opers.top());
                    
                    opers.pop();
                    nums.pop();
                }
                
                nums.push(pre);
                opers.push(s[i]);
                
                pre = 0;
            }
            else if(isdigit(s[i]))
            {
                pre = pre*10+s[i] - '0';
            }
        }
        
        return nums.top();
        
    }
};
