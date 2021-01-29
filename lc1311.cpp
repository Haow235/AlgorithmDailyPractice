class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        // vector<unordered_map<string, int>> lv;
        
        int n = friends.size();
        vector<int> visited(n, 0);
        
        unordered_map<string, int> vs;
        queue<int> person;
        person.push(id);
        visited[id] = 1;
        
        int curl = 0;
        vector<string> re;
        
        while(!person.empty())
        {
            int size = person.size();
            while(size-->0)
            {
                int curp = person.front();
                person.pop();
                
                if(curl == level)
                {
                    for(auto& s: watchedVideos[curp])
                    {
                        vs[s]++;
                    }
                }
                
                for(auto p: friends[curp])
                {
                    if(!visited[p])
                    {
                        person.push(p);
                        visited[p] = 1;
                    }
                }
            }
            
            if(curl == level)
                break;
            
            curl++;
        }
        
        // sort all the videos by their frequency
        vector<pair<string, int>> vvs;
        for(auto it=vs.begin(); it!= vs.end(); it++)
        {
            vvs.push_back({it->first, it->second});
        }
        
        sort(vvs.begin(), vvs.end(), [](const pair<string, int>& lh, const pair<string, int>& rh){
            if(lh.second != rh.second)
                return lh.second < rh.second;
            else
                return lh.first < rh.first;
        });
        
        for(auto& p: vvs)
        {
            re.push_back(p.first);
        }
            
            
        
        return re;
        
        
    }
};
