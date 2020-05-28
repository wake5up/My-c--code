//员工的重要性

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
    void dfs(unordered_map<int,Employee*>& m,int& num,int id)
    {
        num+=m[id]->importance;
        for(auto e:m[id]->subordinates)
        {
            dfs(m,num,e);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        if(employees.empty())
            return 0;
        unordered_map<int,Employee*> m;
        for(auto& e:employees)
        {
            m[e->id]=e;
        }
        int num=0;
        dfs(m,num,id);
        return num;
    }
};