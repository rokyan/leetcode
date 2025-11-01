// https://leetcode.com/problems/maximize-alternating-sum-using-swaps/description/

class Solution
{
public:
    long long maxAlternatingSum(const std::vector<int>& nums,
        const std::vector<std::vector<int>>& swaps)
    {
        const int n = std::size(nums);

        std::vector<std::vector<int>> graph(n);

        for (const auto& e : swaps)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        std::vector<char> vis(n);

        long long res = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vis[i] = true;

                std::queue<int> q;
                q.push(i);

                std::vector<int> idxs;

                while (!q.empty())
                {
                    const int v = q.front();
                    q.pop();

                    idxs.push_back(v);

                    for (int to : graph[v])
                    {
                        if (!vis[to])
                        {
                            vis[to] = true;
                            q.push(to);
                        }
                    }
                }

                int evenCnt = 0;

                std::vector<int> values;
                values.reserve(std::size(idxs));

                for (auto idx : idxs)
                {
                    if (idx % 2 == 0)
                    {
                        evenCnt++;
                    }

                    values.push_back(nums[idx]);
                }

                std::ranges::sort(values, std::greater<int>{});

                for (int i = 0; i < std::size(values); i++)
                {
                    if (i < evenCnt)
                    {
                        res += values[i];
                    }
                    else
                    {
                        res -= values[i];
                    }
                }
            }
        }

        return res;
    }
};