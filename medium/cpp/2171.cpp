// https://leetcode.com/problems/removing-minimum-number-of-magic-beans/description/

class Solution
{
public:
    long long minimumRemoval(std::vector<int>& beans)
    {
        auto s = std::accumulate(std::cbegin(beans), std::cend(beans), 0LL, [](auto a, auto e) {
            return a + e;
        });

        auto res = s;
        auto acc = 0LL;

        std::sort(std::begin(beans), std::end(beans));

        for (auto i = 0; i < std::size(beans); i++)
        {
            res = std::min<long long>(res, acc + s - 1LL * beans[i] * (std::size(beans) - i));

            s -= beans[i];
            acc += beans[i];
        }

        return res;
    }
};