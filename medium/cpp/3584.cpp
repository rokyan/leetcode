// https://leetcode.com/problems/maximum-product-of-first-and-last-elements-of-a-subsequence/description/

class Solution
{
public:
    long long maximumProduct(const std::vector<int>& nums, int m)
    {
        const auto n = std::size(nums);

        std::multiset<int> ms;

        for (auto i = m - 1; i < n; i++)
        {
            ms.insert(nums[i]);
        }

        auto res = 1LL * nums[0] * nums[m - 1];

        for (auto i = 0, j = m - 1; j < n; i++, j++)
        {
            if (nums[i] <= 0)
            {
                res = std::max(res, 1LL * nums[i] * *std::cbegin(ms));
            }
            else
            {
                res = std::max(res, 1LL * nums[i] * *std::crbegin(ms));
            }

            ms.erase(ms.find(nums[j]));
        }

        return res;
    }
};