// https://leetcode.com/problems/course-schedule-iv/description/

class Solution
{
public:
    std::vector<bool> checkIfPrerequisite(int numCourses, std::vector<std::vector<int>>& prerequisites,
        std::vector<std::vector<int>>& queries)
    {
        std::vector<std::vector<bool>> graph(numCourses, std::vector<bool>(numCourses));
        
        for (const auto& pre : prerequisites)
        {
            graph[pre[0]][pre[1]] = true;
        }
        
        for (int k = 0; k < numCourses; k++)
        {            
            for (int i = 0; i < numCourses; i++)
            {
                for (int j = 0; j < numCourses; j++)
                {
                    if (!graph[i][j] && graph[i][k] && graph[k][j])
                    {
                        graph[i][j] = true;
                    }
                }
            }
        }
        
        std::vector<bool> results;
        results.reserve(std::size(queries));
        
        for (const auto& query : queries)
        {
            const auto u = query[0];
            const auto v = query[1];
            
            results.push_back(graph[u][v]);
        }
        
        return results;
    }
};