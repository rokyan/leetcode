class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int goodSubtreeSum(const std::vector<int>& vals, const std::vector<int>& par)
    {
        const auto n = std::size(vals);

        std::vector<std::vector<int>> graph(n);

        for (auto i = 1; i < n; i++)
        {
            graph[par[i]].push_back(i);
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(1024));

        static_cast<void>(dfs(0, graph, dp, vals));

        auto res = 0;

        for (auto v = 0; v < n; v++)
        {
            std::cout << *std::max_element(std::cbegin(dp[v]), std::cend(dp[v])) << std::endl;
            res += *std::max_element(std::cbegin(dp[v]), std::cend(dp[v]));
            res %= mod;
        }

        return res;
    }

private:
    std::vector<int> dfs(int v, const std::vector<std::vector<int>>& graph,
        std::vector<std::vector<int>>& dp, const std::vector<int>& vals)
    {
        std::vector<int> nums;

        for (auto to : graph[v])
        {
            const auto subNums = dfs(to, graph, dp, vals);
            nums.insert(std::end(nums), std::cbegin(subNums), std::cend(subNums));
        }

        nums.push_back(vals[v]);

        for (auto mask = 1; mask < 1024; mask++)
        {
            for (auto num : nums)
            {
                auto fit = true;
                auto numMask = 0;
                auto copied = num;

                while (copied)
                {
                    const auto digit = copied % 10;

                    if (numMask & (1 << digit))
                    {
                        fit = false;
                        break;
                    }

                    if (!(mask & (1 << digit)))
                    {
                        fit = false;
                        break;
                    }

                    numMask |= 1 << digit;
                    copied /= 10;
                }

                if (!fit)
                {
                    continue;
                }

                if (numMask == mask)
                {
                    dp[v][mask] = std::max(dp[v][mask], num);
                }
                else
                {
                    const auto prevMask = mask & ~numMask;

                    if (dp[v][prevMask])
                    {
                        dp[v][mask] = std::max(dp[v][mask], dp[v][prevMask] + num);
                    }
                }
            }
        }

        return nums;
    }
};