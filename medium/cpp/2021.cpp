// https://leetcode.com/problems/brightest-position-on-street/description/

class Solution
{
public:
    int brightestPosition(std::vector<std::vector<int>>& lights)
    {
        std::map<int, int> cnt;

        for (const auto& light : lights)
        {
            cnt[light[0] - light[1]]++;
            cnt[light[0] + light[1] + 1]--;
        }

        auto pos = std::begin(cnt)->first;
        auto c = std::begin(cnt)->second;
        auto r = 0;

        for (const auto& e : cnt)
        {
            r += e.second;

            if (r > c)
            {
                c = r;
                pos = e.first;
            }
        }

        return pos;
    }
};