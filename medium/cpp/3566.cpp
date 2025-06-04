// https://leetcode.com/problems/partition-array-into-two-equal-product-subsets/description/

class Solution
{
public:
    bool checkEqualPartitions(vector<int>& nums, long long target)
    {
        const auto n = std::size(nums);

        for (auto mask = 1; mask + 1 < (1 << n); mask++)
        {
            auto p1 = 1LL;
            auto p2 = 1LL;

            for (auto i = 0; i < n && p1 <= target && p2 <= target; i++)
            {
                if (mask & (1 << i))
                {
                    p1 *= nums[i];
                }
                else
                {
                    p2 *= nums[i];
                }
            }

            if (p1 == target && p2 == target)
            {
                return true;
            }
        }

        return false;
    }
};