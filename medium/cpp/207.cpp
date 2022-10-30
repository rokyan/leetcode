// https://leetcode.com/problems/course-schedule/

class Solution
{
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        build_graph(numCourses, prerequisites);
        
        visited.resize(numCourses);
        
        for (int v = 0; v < numCourses; v++)
        {
            if (!visited[v])
            {
                bool is_cycle_found = traverse(v);
                
                if (is_cycle_found)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    void build_graph(int numCourses, const std::vector<std::vector<int>>& prerequisites)
    {
        graph.resize(numCourses);
        
        for (const auto& edge : prerequisites)
        {
            graph[edge[1]].push_back(edge[0]);
        }
    }
    
    bool traverse(int v)
    {
        visited[v] = 1;
        
        bool found = false;
        
        for (auto to : graph[v])
        {
            if (visited[to] == 1)
            {
                return true;
            }
            
            if (visited[to] == 0)
            {
                found |= traverse(to);
            }
        }
        
        visited[v] = 2;
        
        return found;
    }
    
private:
    std::vector<std::vector<int>> graph;
    std::vector<int> visited;
};