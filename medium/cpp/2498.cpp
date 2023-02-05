// https://leetcode.com/problems/frog-jump-ii/description/

class Solution
{
public:
    int maxJump(std::vector<int>& stones)
    {
        const auto n = static_cast<int>(std::size(stones));
        
        auto res = stones[1];

        for (auto pos = 2; pos < std::size(stones); pos++)
        {
            res = std::max(res, stones[pos] - stones[pos - 2]);
        }

        return res;
    }
};