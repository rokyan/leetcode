// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/

class Solution
{
public:
    int minOperations(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> cnums(nums);

        auto res = 0;

        for (auto i = 0; i + 2 < n; i++)
        {
            if (cnums[i] == 0)
            {
                res++;
                cnums[i + 1] ^= 1;
                cnums[i + 2] ^= 1;
            }
        }

        return cnums[n - 1] && cnums[n - 2] ? res : -1;
    }
};