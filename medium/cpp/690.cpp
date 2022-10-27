// https://leetcode.com/problems/employee-importance/

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
    int getImportance(std::vector<Employee*> employees, int id)
    {       
        for (auto emp : employees)
        {
            id_to_emp[emp->id] = emp;
        }
        
        return solve(id);
    }
    
private:
    int solve(int id)
    {
        auto it = id_to_emp.find(id);
        
        if (it == std::end(id_to_emp))
        {
            return 0;
        }
        
        int sum = it->second->importance;
        
        for (auto to : it->second->subordinates)
        {
            sum += solve(to);
        }
        
        return sum;
    }
    
private:
    std::unordered_map<int, Employee*> id_to_emp;
};