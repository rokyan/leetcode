// https://leetcode.com/problems/maximum-coins-heroes-can-collect/description/

class Solution
{
public:
    std::vector<long long> maximumCoins(std::vector<int>& heroes, std::vector<int>& monsters,
        std::vector<int>& coins)
    {
        const auto m = std::size(monsters);

        std::vector<std::pair<int, int>> data(m);

        for (auto i = 0; i < m; i++)
        {
            data[i] = { monsters[i], coins[i] };
        }

        std::sort(std::begin(data), std::end(data));

        std::vector<long long> pref(m);
        pref[0] = data[0].second;

        for (auto i = 1; i < m; i++)
        {
            pref[i] = pref[i - 1] + data[i].second;
        }

        const auto n = std::size(heroes);

        std::vector<long long> res(n);

        for (auto i = 0; i < n; i++)
        {
            const auto it = std::upper_bound(std::begin(data), std::end(data), heroes[i],
            [](int value, const std::pair<int, int>& e) {
                return value < e.first;
            });

            if (it != std::begin(data))
            {
                const auto d = std::distance(std::begin(data), it);
                res[i] = pref[d - 1];
            }
        }

        return res;
    }
};