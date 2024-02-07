// https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-i/

class Solution
{
public:
    std::vector<int> countOfPairs(int n, int x, int y)
    {
        std::vector<int> res(n);

        for (auto s = 1; s + 1 <= n; s++)
        {
            for (auto f = s + 1; f <= n; f++)
            {
                auto d = f - s;

                d = std::min(d, std::abs(s - x) + std::abs(f - y) + 1);
                d = std::min(d, std::abs(s - y) + std::abs(f - x) + 1);

                res[d - 1]++;
            }
        }

        std::for_each(std::begin(res), std::end(res), [](auto& e) { e *= 2; });

        return res;
    }
};