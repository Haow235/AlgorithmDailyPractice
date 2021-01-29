/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> ems;
        for(Employee* e: employees)
        {
            ems[e->id] = e;
        }
        
        int tim = 0;
        queue<int> person;
        person.push(id);
        
        while(!person.empty())
        {
            int curp = person.front();
            person.pop();
            
            tim += ems[curp]->importance;
            
            for(auto i: ems[curp]->subordinates)
            {
                person.push(i);
            }
        }
        
        return tim;
    }
};
