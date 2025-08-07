// https://leetcode.com/problems/maximum-points-inside-the-square/description/

class Solution
{
public:
    int maxPointsInsideSquare(const std::vector<std::vector<int>>& points, const std::string& s)
    {
        const auto n = std::size(points);
        
        std::vector<std::pair<int, int>> v(n);

        for (auto i = 0; i < n; i++)
        {
            v[i] =
            {
                std::max(std::abs(points[i][0]), std::abs(points[i][1])),
                s[i] - 'a'
            };
        }

        std::ranges::sort(v);

        auto res = 0;
        std::vector<char> used(26);

        for (auto i = 0; i < n; )
        {
            auto j = i;

            for (; j < n && v[j].first == v[i].first; j++)
            {
                if (used[v[j].second])
                {
                    return res;
                }

                used[v[j].second] = true;
            }

            res += j - i;
            i = j;
        }

        return res;
    }
};