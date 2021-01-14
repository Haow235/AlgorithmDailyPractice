class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(src == dst)
            return 0;
        
        // if(K == 0)
        //     return -1;
        
        vector<vector<int>> adj(n);
        vector<vector<int>> prices(n, vector<int>(n, 0));
        
        // build the adj matrix and prices matrix
        for(auto& flight:flights)
        {
            adj[flight[0]].push_back(flight[1]);
            prices[flight[0]][flight[1]] = flight[2];
        }
        
        //find the min cost
        int mincost = INT_MAX;
        int stops = 0;
        queue<int> curposition;
        queue<int> curprice;
        // vector<bool> visited(n, false);
        vector<vector<int>> visited(n, vector<int>(K+2, INT_MAX));
        
        curposition.push(src);
        curprice.push(0);
        // visited[src] = true;
        visited[src][0] = 0;
        
        while(!curposition.empty() && K-->=0)
        {
            stops++;
            int size = curposition.size();
            while(size-->0)
            {
                int curpos = curposition.front();
                int curpri = curprice.front();
                curposition.pop();
                curprice.pop();
                
                for(auto i{0}; i<adj[curpos].size(); i++)
                {
                    if(adj[curpos][i] == dst)
                    {
                        mincost = min(mincost, curpri+prices[curpos][dst]);
                    }
                    else if(curpri + prices[curpos][adj[curpos][i]] < visited[adj[curpos][i]][stops])
                    {
                        // visited[adj[curpos][i]] = true;
                        visited[adj[curpos][i]][stops] = curpri + prices[curpos][adj[curpos][i]];
                        curposition.push(adj[curpos][i]);
                        curprice.push(curpri + prices[curpos][adj[curpos][i]]);
                    }
                }
            }
        }
        
        if(mincost == INT_MAX)
            return -1;
        
        return mincost;
        
    }
};
