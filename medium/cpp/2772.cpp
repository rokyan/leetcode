// https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/description/

class Solution
{
public:
    bool checkArray(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::vector<int> acc(n + 1);

        auto s = 0;

        for (auto i = 0; i + k - 1 < n; i++)
        {
            s += acc[i];

            if (s > nums[i])
            {
                return false;
            }

            const auto rem = nums[i] - s;
            s = nums[i];

            if (i + k < n)
            {
                acc[i + k] -= rem;
            }
        }

        for (auto i = n - k + 1; i < n; i++)
        {
            s += acc[i];
            
            if (nums[i] != s)
            {
                return false;
            }
        }

        return true;
    }
};