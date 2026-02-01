// https://leetcode.com/problems/longest-palindromic-path-in-graph/description/

class Solution
{
public:
    int maxLen(int n, const std::vector<std::vector<int>>& edges, const std::string& label)
    {
        std::vector<std::vector<std::vector<char>>> dp((1 << n) + 1,
            std::vector<std::vector<char>>(n, std::vector<char>(n)));

        std::vector<std::vector<char>> graph(n, std::vector<char>(n));

        for (const auto& edge : edges)
        {
            graph[edge[0]][edge[1]] = graph[edge[1]][edge[0]] = true;
        }

        int res = 1;

        for (int mask = 1; mask <= (1 << n); mask++)
        {
            int count = 0;
            int v = -1;

            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    count++;
                    v = i;
                }
            }

            if (count == 1)
            {
                dp[mask][v][v] = true;
                continue;
            }

            bool found = false;

            for (int u = 0; u < n; u++)
            {
                if (mask & (1 << u))
                {
                    for (int v = 0; v < n; v++)
                    {
                        if (mask & (1 << v))
                        {
                            if (u == v)
                            {
                                continue;
                            }

                            bool skip = false;

                            if (count == 2)
                            {
                                dp[mask][u][v] = dp[mask][v][u] = label[u] == label[v] && graph[u][v];
                                found = dp[mask][u][v];
                            }
                            else
                            {
                                const int prevMask = mask ^ (1 << u) ^ (1 << v);

                                for (int i = 0; i < n && !skip; i++)
                                {
                                    if (prevMask & (1 << i))
                                    {
                                        for (int j = 0; j < n && !skip; j++)
                                        {
                                            if (prevMask & (1 << j))
                                            {
                                                if (label[u] == label[v] && 
                                                    dp[prevMask][i][j] &&
                                                    (graph[u][i] && graph[j][v] || graph[v][i] && graph[j][u]))
                                                {
                                                    dp[mask][u][v] = dp[mask][v][u] = true;
                                                    found = true;
                                                    skip = true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (found)
            {
                res = std::max(res, count);
            }
        }

        return res;
    }
};