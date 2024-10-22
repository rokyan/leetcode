// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000 + 7;

public:
    long long minimumCost(const std::string& source, const std::string& target,
        const std::vector<char>& original, const std::vector<char>& changed, const std::vector<int>& cost)
    {
        std::vector<std::vector<int>> d(26, std::vector<int>(26, inf));

        for (auto i = 0; i < 26; i++)
        {
            d[i][i] = 0;
        }

        for (auto i = 0; i < std::size(original); i++)
        {
            d[original[i] - 'a'][changed[i] - 'a'] =
                std::min(d[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        for (auto k = 0; k < 26; k++)
        {
            for (auto i = 0; i < 26; i++)
            {
                for (auto j = 0; j < 26; j++)
                {
                    if (d[i][j] > d[i][k] + d[k][j])
                    {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }

        auto res = 0LL;

        for (auto i = 0; i < std::size(source); i++)
        {
            const auto t = d[source[i] - 'a'][target[i] - 'a'];

            if (t == inf)
            {
                return -1;
            }

            res += t;
        }

        return res;
    }
};