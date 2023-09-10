// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/

class Solution
{
public:
    int findSmallestInteger(std::vector<int>& nums, int value)
    {
        const auto n = std::size(nums);

        std::vector<int> probe(value);

        for (auto i = 0; i < n; i++)
        {
            probe[(nums[i] % value + value) % value]++;
        }

        auto res = n;

        for (auto i = 0; i < n; i++)
        {
            if (probe[i % value])
            {
                probe[i % value]--;
            }
            else
            {
                res = i;
                break;
            }
        }

        return res;
    }
};