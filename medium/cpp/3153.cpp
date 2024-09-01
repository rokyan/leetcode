// https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs/description/

class Solution
{
public:
    long long sumDigitDifferences(std::vector<int>& nums)
    {
        auto res = 0LL;

        while (nums.front() > 0)
        {
            std::array<int, 10> freq{ 0 };

            for (auto& num : nums)
            {
                freq[num % 10]++;
                num /= 10;
            }

            for (auto d = 0; d < 10; d++)
            {
                res += 1LL * freq[d] * (std::size(nums) - freq[d]);
            }
        }

        return res / 2;
    }
};