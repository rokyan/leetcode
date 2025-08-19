// https://leetcode.com/problems/maximum-k-to-sort-a-permutation/description/

class Solution
{
public:
    int sortPermutation(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<char> vis(n);
        std::vector<int> inv(n);

        auto res = (1 << 30) - 1;
        auto sorted = true;

        for (auto i = 0; i < n; i++)
        {
            if (!vis[i] && nums[i] != i)
            {
                sorted = false;
                auto j = i;

                while (!vis[j])
                {
                    vis[j] = true;
                    res &= nums[j];
                    j = nums[j];
                }
            }
        }

        return sorted ? 0 : res;
    }
};