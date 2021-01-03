class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // int n = ;
        if(prerequisites.size() == 0)
            return true;
        
        // build graph, represented with a adjacent matrix
        vector<vector<int>> graph(numCourses);
        // vector<int> indegree(numCourses, 0);
        int indegree[numCourses];
        memset(indegree,0,sizeof(indegree));
        
        for(auto& prereq: prerequisites)
        {
            graph[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }
        
        // topological sort the courses, until we sort all courses or there're no course can choose (no courses with 0 indegree)
        queue<int> validcourse;
        int i=0;
        for(; i<numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                validcourse.push(i);
            }
        }
        
        // cout<<"ok"<<endl;
        
        int selected_courses = 0;
        int tempcourse = 0;
        while(validcourse.size())
        {
            tempcourse = validcourse.front();
            validcourse.pop();
            selected_courses++;
            
            for(i=0; i<graph[tempcourse].size(); i++)
            {
                indegree[graph[tempcourse][i]]--;
                if(indegree[graph[tempcourse][i]] == 0)
                {
                    validcourse.push(graph[tempcourse][i]);
                }
            }
        }
        
        if(selected_courses == numCourses)
            return true;
        return false;
        
    }
};
