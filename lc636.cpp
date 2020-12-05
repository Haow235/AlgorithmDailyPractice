class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> re(n, 0);
        stack<int> funcs;
        int pretime=0;
        
        for(auto& log: logs)
        {
            vector<int> info = parseLog(log);
            
            if(!funcs.empty())
            {
                if(info[1] == 1)
                {
                    // cout<<"function "<<funcs.top()<<" add "<<(info[2] - pretime) << endl;
                    re[funcs.top()] += (info[2] - pretime);
                    funcs.push(info[0]);
                    pretime = info[2];
                }
                else
                {
                    // cout<<"function "<<funcs.top()<<" add "<<(info[2] - pretime + 1) << endl;
                    re[funcs.top()] += (info[2] - pretime + 1);
                    funcs.pop();
                    pretime = info[2]+1;
                }
            }
            else
            {
                funcs.push(info[0]);
                pretime = info[2];
            }
        }
        
        return re;        
    }
    
private:
    vector<int> parseLog(string& log)
    {
        vector<int> re(3, 0); //0: id, 1:start|end, 2: time
        // if(log.size() == 0)
        //     return re;
        
        int id = 0;
        int i = 0;
        for(; i<log.size() && log[i] != ':'; i++)
        {
            id = id*10 + log[i]-'0';
        }
        
        re[0] = id;
        
        i++;
        if(log[i] == 's')
        {
            re[1] = 1;
        }
        
        for(; i<log.size() && log[i] != ':'; i++);
        
        i++;
        for(; i<log.size(); i++)
        {
            re[2] = re[2]*10 + log[i] - '0';
        }
        
        return re;
            
    }
};
