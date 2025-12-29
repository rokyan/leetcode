// https://leetcode.com/problems/sum-of-perfect-square-ancestors/description/

class Solution
{
private:
    using graph_type = std::vector<std::vector<int>>;

public:
    long long sumOfAncestors(int n, const std::vector<std::vector<int>>& edges, const std::vector<int>& nums)
    {
        const graph_type graph{build_graph(n, edges)};

        std::vector<int> parts(n);

        for (int i = 0; i < n; i++)
        {
            parts[i] = take_incomplete_part(nums[i]);
        }

        std::unordered_map<int, int> freq;
        long long res = 0LL;

        dfs(0, -1, graph, parts, freq, res);

        return res;
    }

private:
    graph_type build_graph(int n, const std::vector<std::vector<int>>& edges)
    {
        graph_type graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    int take_incomplete_part(int n)
    {
        int part = 1;

        for (int d = 2; d * d <= n; d++)
        {
            int times = 0;

            while (n % d == 0)
            {
                times++;
                n /= d;
            }

            if (times & 1)
            {
                part *= d;
            }
        }

        if (n > 1)
        {
            part *= n;
        }

        return part;
    }

    void dfs(int v, int parent, const graph_type& graph, std::vector<int>& parts,
        std::unordered_map<int, int>& freq, long long& res)
    {
        res += freq[parts[v]];
        freq[parts[v]]++;

        for (auto to : graph[v])
        {
            if (to != parent)
            {
                dfs(to, v, graph, parts, freq, res);
            }
        }

        freq[parts[v]]--;
    }
};