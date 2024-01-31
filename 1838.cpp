// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution
{
public:
    int maxFrequency(std::vector<int>& nums, int k)
    {
        std::sort(std::begin(nums), std::end(nums));
        
        const auto n = std::size(nums);

        std::vector<long long> pref(n);

        for (auto i = 0; i < n; i++)
        {
            pref[i] = nums[i];

            if (i > 0)
            {
                pref[i] += pref[i - 1];
            }
        }

        auto res = 0;

        for (auto l = 0, r = 0; r < n; r++)
        {
            auto cur = 1LL * (r - l + 1) * nums[r] - (pref[r] - (l > 0 ? pref[l - 1] : 0));

            while (cur > k)
            {
                cur -= (nums[r] - nums[l++]);
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};