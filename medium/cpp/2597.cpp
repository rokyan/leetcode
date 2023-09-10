// https://leetcode.com/problems/the-number-of-beautiful-subsets/description/

class Solution
{
public:
    int beautifulSubsets(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::vector<int> probe(n);

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                if (i != j && std::abs(nums[i] - nums[j]) == k)
                {
                    probe[i] |= (1 << j);
                }
            }
        }

        auto res = 0;

        for (auto mask = 1; mask < (1 << n); mask++)
        {
            auto check = true;

            for (auto i = 0; i < n && check; i++)
            {
                if ((mask & (1 << i)) && (mask & probe[i]))
                {
                    check = false;
                }
            }

            res += check;
        }

        return res;
    }
};