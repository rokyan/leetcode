// https://leetcode.com/problems/count-increasing-quadruplets/description/

class Solution
{
public:
    long long countQuadruplets(std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));

        std::vector<int> pref(n + 1);

        for (auto i = nums[0]; i <= n; i++)
        {
            pref[i] = 1;
        }

        auto res = 0LL;

        for (auto i = 1; i + 2 < n; i++)
        {
            int c = nums[i] < nums[n - 1];

            for (auto j = n - 2; j > i; j--)
            {
                if (nums[j] < nums[i])
                {
                    res += 1LL * pref[nums[j]] * c;
                }

                if (nums[j] > nums[i])
                {
                    c++;
                }
            }

            for (auto j = nums[i]; j <= n; j++)
            {
                pref[j]++;
            }
        }

        return res;
    }
};