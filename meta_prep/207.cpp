class Solution
{
public:
    bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites)
    {
        std::vector<std::vector<int>> graph(numCourses);

        for (const auto& prereq : prerequisites)
        {
            graph[prereq[1]].push_back(prereq[0]);
        }

        std::vector<int> color(numCourses);

        for (auto v = 0; v < numCourses; v++)
        {
            if (color[v] == 0)
            {
                if (dfs(v, color, graph))
                {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool dfs(int v, std::vector<int>& color,
        const std::vector<std::vector<int>>& graph)
    {
        if (color[v] == 1)
        {
            return true;
        }

        if (color[v] == 2)
        {
            return false;
        }

        color[v] = 1;

        for (auto to : graph[v])
        {
            if (dfs(to, color, graph))
            {
                return true;
            }
        }

        color[v] = 2;

        return false;
    }
};