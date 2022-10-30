// https://leetcode.com/problems/course-schedule-ii/

class Solution
{
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        build_graph(numCourses, prerequisites);
        
        visited.resize(numCourses);
        
        for (int v = 0; v < numCourses; v++)
        {
            if (!visited[v] && dfs(v))
            {
                return {};
            }
        }
        
        std::reverse(std::begin(order), std::end(order));
        return order;
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
    
    bool dfs(int v)
    {
        visited[v] = 1;
        
        for (auto to : graph[v])
        {
            if (visited[to] == 1)
            {
                return true;
            }
            
            if (visited[to] == 0 && dfs(to))
            {
                return true;
            }
        }
        
        visited[v] = 2;
        
        order.push_back(v);
        
        return false;
    }
    
private:
    std::vector<std::vector<int>> graph;
    std::vector<int> visited;
    std::vector<int> order;
};