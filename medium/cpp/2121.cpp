// https://leetcode.com/problems/intervals-between-identical-elements/description/

class Solution
{
public:
    std::vector<long long> getDistances(std::vector<int>& arr)
    {
        std::unordered_map<int, std::vector<int>> m;

        for (auto p = 0; p < std::size(arr); p++)
        {
            m[arr[p]].push_back(p);
        }

        std::vector<long long> res(std::size(arr));

        for (const auto& e : m)
        {
            const auto& ps = e.second;
            const auto n = std::size(ps);

            auto s = std::accumulate(std::begin(ps), std::end(ps), 0LL);
            auto ss = 0LL;

            for (auto i = 0; i < n; i++)
            {
                s -= ps[i];
                res[ps[i]] = 1LL * i * ps[i] - ss + s - 1LL * (n - i - 1) * ps[i];
                ss += ps[i];
            }

        }

        return res;
    }
};