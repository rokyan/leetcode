// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/

class Solution
{
public:
    int maxConsecutive(int bottom, int top, std::vector<int>& special)
    {
        std::sort(std::begin(special), std::end(special));

        auto res = std::max(special.front() - bottom, top - special.back());

        for (auto i = 1; i < std::size(special); i++)
        {
            res = std::max(res, special[i] - special[i - 1] - 1);
        }

        return res;
    }
};