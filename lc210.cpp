// Need to redo next time
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> re;
        if(numCourses <= 0)
            return re;
        
        map<int, int> prenum;
        vector<vector<int>> pregra(numCourses, vector<int>(numCourses, 0));
        
        for(auto prereq: prerequisites)
        {
            prenum[prereq[0]]++;
            pregra[prereq[0]][prereq[1]] = 1;
        }
        
        int nextcourse = -1;
        while(re.size() < numCourses)
        {
//             Find the next courses rely on no other courses
            nextcourse = -1;
            for(auto i{0}; i<numCourses; i++)
            {
                if(prenum[i] == 0)
                {
                    re.push_back(i);
                    prenum[i] = -1;
                    nextcourse = i;
                    break;
                }
            }
            
            if(nextcourse == -1)
                return vector<int>{};
            
            for(auto i{0}; i<numCourses; i++)
            {
                if(pregra[i][nextcourse] == 1)
                {
                    pregra[i][nextcourse] = 0;
                    prenum[i]--;
                }
            }
        }
        
        return re;
        
    }
};
