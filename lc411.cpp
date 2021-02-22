class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        /*
        base case: only one number => have diff length
        each char of target can located in the abbre, or not
        */
        
        /*
        use brute forch to find all the possible abbre, and find the shortest one
        curstr, precount
        for each char, if its a char, curstr = curstr + precount + char, precount = 0;
        if its a precout, precount ++;
        if reach the end of the target, check if it's avalid abbre, update the shortest
        */
        int n = target.size();
        bool samestart = false, sameend = false;
        
        set<string> dict;
        for(auto& s: dictionary )
        {
            if(s.size() == n)
            {
                dict.insert(s);
                if(s[0] == target[0])
                    samestart = true;
                
                if(s[n-1] == target[n-1])
                    sameend = true;
            }
                
        }
        
        if(dict.size() == 0)
            return to_string(target.size());
        
        if(!samestart)
        {
            re = target.substr(0, 1);
            if(n-1 > 0)
                re += to_string(n-1);
            return re;
        }
        
        if(!sameend)
        {
            return to_string(n-1) + target.substr(n-1);
        }
        
        string curstr = "";
        int precount = 0;
        
        minAbbreviationUtil(target, dict, curstr, precount, 0);
        
        return re;
    }

private:
    string re ="";
    int shortest = INT_MAX;
    
    void minAbbreviationUtil(string& target, set<string>& dict, string curstr, int precount, int p)
    {
        // base case, reach the end of the target
        if(p == target.size())
        {
            if(precount > 0)
            {
                curstr += to_string(precount);
            }
            
            // cout<<curstr<<" "<<precount<<endl;
            
            //count length
            int length = 0;
            int count = 0;
            for(auto i{0}; i<curstr.size(); i++)
            {
                if(isdigit(curstr[i]))
                {
                    count = count*10 + curstr[i]-'0';
                }
                else
                {
                    if(count != 0)
                    {
                        count = 0;

                        length++;
                    }

                    length++;
                }
            }
            
            if(count != 0)
                length++;
            
            // check if curstr is valid
            bool valid = true;
            
            for(auto& s: dict)
            {
                int j = 0;
                count = 0;
                for(auto i{0}; i<curstr.size(); i++)
                {
                    if(isdigit(curstr[i]))
                    {
                        count = count*10 + curstr[i]-'0';
                    }
                    else
                    {
                        if(count != 0)
                        {
                            j+=count;
                            count = 0;
                        }
                        
                        if(s[j] != curstr[i])
                        {
                            break;
                        }
                        
                        j++;
                    }
                }
                
                if(count != 0)
                {
                    j += count;
                }
                
                if(j == s.size())
                {
                    valid = false;
                    break;
                }
            }
            
            if(valid && length < shortest)
            {
                shortest = length;
                re = curstr;
            }
            
            return;
        }
        
        // each char can either in the abbrevaiation, or not
        minAbbreviationUtil(target, dict, curstr, precount+1, p+1);
        if(precount != 0)
        {
            curstr += to_string(precount);
            precount = 0;
        }
        curstr += target.substr(p, 1);
        minAbbreviationUtil(target, dict, curstr, precount, p+1);
        return;
    }
};
