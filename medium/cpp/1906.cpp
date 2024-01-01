// https://leetcode.com/problems/minimum-absolute-difference-queries/description/

class Solution
{
public:
    std::vector<int> minDifference(std::vector<int>& nums, std::vector<std::vector<int>>& queries)
    {
        const auto n = std::size(nums);

        std::vector<std::vector<int>> pref(n, std::vector<int>(100));

        for (auto i = 0; i < n; i++)
        {
            if (i > 0)
            {
                for (auto v = 0; v < 100; v++)
                {
                    pref[i][v] += pref[i - 1][v];
                }
            }

            pref[i][nums[i] - 1]++;
        }

        std::vector<int> ret;
        ret.reserve(std::size(queries));

        for (const auto& q : queries)
        {
            const auto l = q[0];
            const auto r = q[1];

            std::vector<int> cur(pref[r]);

            if (l > 0)
            {
                for (auto v = 0; v < 100; v++)
                {
                    cur[v] -= pref[l - 1][v];
                }
            }

            auto last = -1;
            auto res = -1;

            for (auto v = 0; v < 100; v++)
            {
                if (cur[v] > 0)
                {
                    if (last != -1)
                    {
                        const auto d = v - last;

                        res = res == -1 ? d : std::min(res, d);
                    }

                    last = v;
                }
            }

            ret.push_back(res);
        }

        return ret;
    }
};