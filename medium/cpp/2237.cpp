// https://leetcode.com/problems/count-positions-on-street-with-required-brightness/

class Solution
{
public:
    int meetRequirement(int n, std::vector<std::vector<int>>& lights, std::vector<int>& requirement)
    {
        std::vector<int> acc(n);

        for (const auto& light : lights)
        {
            const auto left = std::max(0, light[0] - light[1]);
            const auto right = std::min(n - 1, light[0] + light[1]);

            acc[left]++;

            if (right + 1 < n)
            {
                acc[right + 1]--;
            }
        }

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            if (i > 0)
            {
                acc[i] += acc[i - 1];
            }

            res += acc[i] >= requirement[i];
        }

        return res;
    }
};