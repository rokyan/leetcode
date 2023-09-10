// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/

class Solution
{
public:
    int maxEqualRowsAfterFlips(std::vector<std::vector<int>>& matrix)
    {
        std::map<std::vector<int>, int> cnt;

        for (const auto& row : matrix)
        {
            cnt[row]++;
        }

        auto res = 0;

        for (const auto& e : cnt)
        {
            std::vector<int> re(e.first);

            for (auto& e : re)
            {
                e ^= 1;
            }

            res = std::max(res, e.second + cnt[re]);
        }

        return res;
    }
};