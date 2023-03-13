// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/

class Solution
{
public:
    int minOperations(std::vector<int>& nums, std::vector<int>& numsDivide)
    {
        auto gcd_val = std::accumulate(std::begin(numsDivide), std::end(numsDivide), 0, gcd);

        std::sort(std::begin(nums), std::end(nums));

        for (auto p = 0; p < std::size(nums); p++)
        {
            if (p > 0 && nums[p] == nums[p - 1])
            {
                continue;
            }

            if ((gcd_val % nums[p]) == 0)
            {
                return p;
            }
        }

        return -1;
    }

private:
    static int gcd(int x, int y)
    {
        return (y == 0) ? x : gcd(y, x % y);
    }
};