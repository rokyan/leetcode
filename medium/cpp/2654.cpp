// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/

class Solution
{
public:
    int minOperations(std::vector<int>& nums)
    {
        const auto ones = std::count(std::begin(nums), std::end(nums), 1);

        if (ones > 0)
        {
            return std::size(nums) - ones;
        }

        auto v = -1;

        for (auto i = 1; i < std::size(nums); i++)
        {
            auto t = nums[i];

            for (auto j = i - 1; j >= 0; j--)
            {
                t = gcd(t, nums[j]);

                if (t == 1)
                {
                    v = (v == -1) ? i - j + 1 : std::min(v, i - j + 1);
                }
            }
        }

        return (v == -1) ? v : v - 1 + std::size(nums) - 1;
    }

private:
    int gcd(int x, int y)
    {
        if (x == 0)
        {
            return y;
        }

        return gcd(y % x, x);
    }
};