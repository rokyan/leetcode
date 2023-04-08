// https://leetcode.com/problems/mice-and-cheese/description/

class Solution
{
public:
    int miceAndCheese(std::vector<int>& reward1, std::vector<int>& reward2, int k)
    {
        std::vector<std::pair<int, int>> r(std::size(reward1));

        std::transform(std::begin(reward1), std::end(reward1), std::begin(reward2),
            std::begin(r), [](auto e1, auto e2) -> std::pair<int, int> {
                return { e1, e2 };
        });

        std::sort(std::begin(r), std::end(r), [](const auto& e1, const auto& e2) {
            return e1.first - e1.second > e2.first - e2.second;
        });

        auto res = 0;

        for (auto i = 0; i < std::size(r); i++)
        {           
            res += (i < k) ? r[i].first : r[i].second;
        }

        return res;
    }
};