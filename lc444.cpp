class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        
        // adj matrix to store the dependencies
        // use a vector to store the indegree of each number
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1, 0);
        vector<bool> appear(n+1, false);
        
        for(auto& seq: seqs)
        {
            if(seq[0] > n || seq[0]<1)
                return false;
            appear[seq[0]] = true;
            for(auto j{1}; j<seq.size(); j++)
            {
                if(seq[j] > n || seq[j]<1)
                    return false;
                appear[seq[j]] = true;
                adj[seq[j-1]].push_back(seq[j]);
                indegree[seq[j]]++;
            }
            
        }
        
        int allnum = 0;
        for(auto j{1}; j<=n; j++)
        {
            if(appear[j])
                allnum++;
        }
        
        if(allnum != n)
            return false;
        
        bool re = false;
        int i = 0;
        int count = 0;
        int next = -1;
        
        for(auto j{1}; j<=n; j++)
        {
            if(indegree[j] == 0)
            {
                if(count!=0)
                    return false;
                
                count++;
                next = j;
            }
        }
        
        while(i<n)
        {
            if(org[i] != next)
                return false;
            
            i++;
            count = 0;
            for(auto j: adj[next])
            {
                indegree[j]--;
                if(indegree[j] == 0)
                {
                    if(count!=0)
                        return false;
                    
                    count++;
                    next = j;
                }
            }
        }
        
        return true;
        
    }
};
