// https://leetcode.com/problems/validate-binary-tree-nodes/description/

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        std::vector<char> root(n, true);
        std::vector<std::vector<int>> graph(n);

        auto m = 0;

        for (auto v = 0; v < n; v++)
        {
            auto to = leftChild[v];

            if (to != -1)
            {
                graph[v].push_back(to);
                root[to] = false;
                m++;
            }

            to = rightChild[v];

            if (to != -1)
            {
                graph[v].push_back(to);
                root[to] = false;
                m++;
            }
        }

        if (m + 1 != n)
        {
            return false;
        }

        auto root_idx = -1;

        for (auto v = 0; v < n; v++)
        {
            if (root[v])
            {
                if (root_idx == -1)
                {
                    root_idx = v;
                }
                else
                {
                    return false;
                }
            }
        }

        std::vector<char> visited(n);

        dfs(root_idx, graph, visited);

        return std::all_of(std::cbegin(visited), std::cend(visited), [](auto e) { return e; });
    }

private:
    void dfs(int v, const std::vector<std::vector<int>>& graph, std::vector<char>& visited)
    {
        visited[v] = true;

        for (auto to : graph[v])
        {
            if (!visited[to])
            {
                visited[to] = true;
                dfs(to, graph, visited);
            }
        }
    }
};