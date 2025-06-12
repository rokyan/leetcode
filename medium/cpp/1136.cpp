// https://leetcode.com/problems/parallel-courses/description/

class Solution
{
public:
    int minimumSemesters(int n, const std::vector<std::vector<int>>& relations)
    {
        std::vector<std::vector<int>> graph(n);

        for (const auto& relation : relations)
        {
            graph[relation[0] - 1].push_back(relation[1] - 1);
        }

        std::vector<char> color(n);

        for (auto v = 0; v < n; v++)
        {
            if (color[v] == 0)
            {
                if (dfs(v, graph, color))
                {
                    return -1;
                }
            }
        }

        std::vector<int> mem(n, -1);

        auto res = 0;

        for (auto v = 0; v < n; v++)
        {
            res = std::max(res, dfs2(v, graph, mem));
        }

        return res;
    }

private:
    bool dfs(int v, const std::vector<std::vector<int>>& graph,
        std::vector<char>& color)
    {
        color[v] = 1;

        for (const auto to : graph[v])
        {
            if (color[to] == 1)
            {
                return true;
            }
            else if (color[to] == 0)
            {
                if (dfs(to, graph, color))
                {
                    return true;
                }
            }
        }

        color[v] = 2;

        return false;
    }

    int dfs2(int v, const std::vector<std::vector<int>>& graph,
        std::vector<int>& mem)
    {
        if (mem[v] != -1)
        {
            return mem[v];
        }

        auto len = 0;

        for (auto to : graph[v])
        {         
            len = std::max(len, dfs2(to, graph, mem));
        }

        mem[v] = len + 1;
        return mem[v];
    }
};