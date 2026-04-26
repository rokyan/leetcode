// https://leetcode.com/problems/count-connected-subgraphs-with-even-node-sum/description/

class Solution
{
public:
    int evenSumSubgraphs(const std::vector<int>& nums,
        const std::vector<std::vector<int>>& edges)
    {
        const int n = nums.size();

        std::vector<std::vector<char>> graph(n, std::vector<char>(n));

        for (const auto& edge : edges)
        {
            graph[edge[0]][edge[1]] = graph[edge[1]][edge[0]] = true;
        }

        int res = 0;

        for (int mask = 1; mask < (1 << n); mask++)
        {
            int sum = 0;
            int cnt = 0;
            int start = -1;

            for (int v = 0; v < n; v++)
            {
                if (mask & (1 << v))
                {
                    sum += nums[v];
                    cnt++;
                    start = v;
                }
            }

            std::vector<char> used(n);

            if (sum % 2 == 0 && dfs(start, mask, n, used, graph) == cnt)
            {
                res++;
            }
        }

        return res;
    }

private:
    int dfs(int v, int mask, int n, std::vector<char>& used, const std::vector<std::vector<char>>& graph)
    {
        int cnt = 1;
        used[v] = true;

        for (int to = 0; to < n; to++)
        {
            if (graph[v][to] && !used[to] && (mask & (1 << to)))
            {
                cnt += dfs(to, mask, n, used, graph);
            }
        }

        return cnt;
    }
};