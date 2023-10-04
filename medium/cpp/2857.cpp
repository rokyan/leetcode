// https://leetcode.com/problems/count-pairs-of-points-with-distance-k/description/

class Solution
{
public:
    int countPairs(std::vector<std::vector<int>>& coordinates, int k)
    {
        std::map<std::pair<int, int>, int> cnt;

        auto res = 0;

        for (auto&& c : coordinates)
        {
            const auto x = c[0];
            const auto y = c[1];

            for (auto a = 0; a <= k; a++)
            {
                const auto b = k - a;

                const auto xx = x ^ a;
                const auto yy = y ^ b;

                if (const auto it = cnt.find({ xx, yy }); it != std::end(cnt))
                {
                    res += it->second;
                }
            }

            cnt[{x, y}]++;
        }

        return res;
    }
};