class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        
        string curdir;
        int prep=0, i=0;
        for(; i<=path.size(); i++)
        {
            if(i == path.size() || path[i] == '/')
            {
                if(i != prep) 
                {
                    curdir = path.substr(prep, i-prep);
                    if(curdir == "..")
                    {
                        if(!dirs.empty())
                        {
                            dirs.pop_back();
                        }
                    }
                    else if(curdir == ".")
                    {
                        
                    }
                    else
                    {
                        dirs.push_back(curdir);
                    }                    
                }
                
                prep = i+1;
            }
        }

        
        // construct the result
        string re = "";
        for(i=0; i<dirs.size(); i++)
        {
            re += "/";
            re += dirs[i];
        }
        
        if(re == "")
            return "/";
        
        return re;
    }
};
