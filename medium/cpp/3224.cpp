// https://leetcode.com/problems/minimum-array-changes-to-make-differences-equal/description/

class Solution
{
public:
    int minChanges(const std::vector<int>& nums, int k)
    {
        std::vector<int> s(k + 2);

        const auto n = std::size(nums);

        for (auto i = 0; i * 2 < n; i++)
        {
            const auto a = nums[i];
            const auto b = nums[n - i - 1];

            const auto l = 0;
            const auto r = std::max({ a, b, k - a, k - b });

            s[0] += 2;
            s[k + 1] -= 2;
            s[l]--;
            s[r + 1]++;
            s[std::abs(a - b)]--;
            s[std::abs(a - b) + 1]++;
        }

        auto res = s[0];

        for (auto i = 0, acc = 0; i < k + 1; i++)
        {
            acc += s[i];
            res = std::min(res, acc);
        }

        return res;
    }
};