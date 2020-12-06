class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> curs;
        
        for(int i{0}; i<s.size(); i++)
        {
            if(curs.empty() || s[i] != curs.top().first)
            {
                curs.push({s[i], 1});
            }
            else
            {
                if(curs.top().second == k-1)
                {

                    curs.pop();
                }
                else
                {
                    // curs.push({s[i], curs.top().second+1});
                    curs.top().second+=1;
                }
            }
        }
        
        string re = "";
        while(curs.size())
        {
            re = string(curs.top().second, curs.top().first)+ re;
            curs.pop();
        }
        
        return re;
        
    }
};
