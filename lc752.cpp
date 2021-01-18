class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        vector<int> visited(10000, 0); // 1 visited, 2 deadends
        
        int start = 0, dest = stoi(target);
        
        for(auto& s: deadends)
        {
            visited[stoi(s)] = 2;
        }
        
        // visited[0] = 1;
        
        queue<int> states;
        states.push(start);
        
        int steps = 0;
        // vector<int> next{10, 100, 1000, 10000};
        
        while(!states.empty())
        {
            steps++;
            
            int size = states.size();
            while(size-->0)
            {
                int cur = states.front();
                states.pop();
                
                if(visited[cur])
                    continue;
                
                visited[cur] = 1;
                
                if(cur == dest)
                    return steps-1;
                
                vector<int> num(4, 0);
                for(auto i{0}; i<4; i++)
                {
                    num[i] = cur%10;
                    cur/=10;
                }
                
                for(auto i{0}; i<4; i++)
                {
                    int old = num[i];
                    if(num[i] == 9)
                        num[i] = 0;
                    else
                        num[i] += 1;
                    
                    int newnum = num[0] + num[1]*10 + num[2]*100 + num[3]*1000;
                    if(visited[newnum] == 0)
                    {
                        states.push(newnum);
                        // visited[newnum] = 1;
                    }
                    
                    if(old == 0)
                    {
                        num[i] = 9;
                    }
                    else
                    {
                        num[i] = old - 1;
                    }
                    newnum = num[0] + num[1]*10 + num[2]*100 + num[3]*1000;
                    
                    if(visited[newnum] == 0)
                    {
                        states.push(newnum);
                        // visited[newnum] = 1;
                    }
                    
                    num[i] = old;
                }
            }
            
        }
        
        return -1;
    }
};
