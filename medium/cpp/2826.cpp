// https://leetcode.com/problems/sorting-three-groups/description/

class Solution
{
public:
    int minimumOperations(std::vector<int>& nums)
    {
        const auto n = std::size(nums);
        auto res = -1;

        for (auto i = 0; i <= n; i++)
        {
            for (auto j = 0; j <= n - i; j++)
            {
                const auto k = n - i - j;

                if (i + j + k < n)
                {
                    continue;
                }

                auto ops = 0;

                for (auto p = 0; p < i; p++)
                {
                    if (nums[p] != 1)
                    {
                        ops++;
                    }
                }

                for (auto p = i; p < i + j; p++)
                {
                    if (nums[p] != 2)
                    {
                        ops++;
                    }
                }

                for (auto p = i + j; p < i + j + k; p++)
                {
                    if (nums[p] != 3)
                    {
                        ops++;
                    }
                }

                if (res == -1 || ops < res)
                {
                    res = ops;
                }
            }
        }

        return res;
    }
};