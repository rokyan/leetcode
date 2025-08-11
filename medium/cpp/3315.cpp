// https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/

class Solution
{
public:
    std::vector<int> minBitwiseArray(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);
        std::vector<int> res(n, -1);

        for (auto i = 0; i < n; i++)
        {
            auto p = 0;

            while ((1 << p) < nums[i])
            {
                const auto v = nums[i] - (1 << p);

                if ((v | (v + 1)) == nums[i])
                {
                    res[i] = v;
                }

                p++;
            }
        }

        return res;
    }

private:
    int gen(int x)
    {
        for (auto i = 1; i <= x; i++)
        {
            if ((i | (i + 1)) == x)
            {
                return i;
            }
        }

        return -1;
    }
};