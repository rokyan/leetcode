// https://leetcode.com/problems/minimum-impossible-or/description/

class Solution
{
public:
    int minImpossibleOR(std::vector<int>& nums)
    {
        std::unordered_set<int> un(std::begin(nums), std::end(nums));

        auto n = 1LL;

        while (true)
        {
            const auto it = un.find(n);

            if (it == std::cend(un))
            {
                return n;
            }

            n *= 2;
        }

        return n;
    }
};