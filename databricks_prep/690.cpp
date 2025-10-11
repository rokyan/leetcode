/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int getImportance(const std::vector<Employee*>& employees, int id)
    {
        for (auto e : employees)
        {
            ids[e->id] = e;
        }

        return dfs(ids[id]);
    }

private:
    int dfs(Employee* v)
    {
        int total = v->importance;

        for (auto to : v->subordinates)
        {
            total += dfs(ids[to]);
        }

        return total;
    }

private:
    std::unordered_map<int, Employee*> ids;
};