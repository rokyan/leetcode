// https://leetcode.com/problems/number-of-subarrays-having-even-product/description/

class Solution
{
public:
    long long evenProduct(vector<int>& nums)
    {
        const auto n = std::size(nums);

        auto last = -1;
        auto acc = 0LL;

        for (auto i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 1)
            {
                acc += i - last;
            }
            else
            {
                last = i;
            }
        }

        return 1LL * n * (n + 1) / 2 - acc;
    }
};