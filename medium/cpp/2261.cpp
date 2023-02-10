// https://leetcode.com/problems/k-divisible-elements-subarrays/description/

class Solution
{
public:
    int countDistinct(std::vector<int>& nums, int k, int p)
    {
        const auto n = static_cast<int>(std::size(nums));

        std::string s;
        s.reserve(n);

        std::vector<int> pref(n);

        for (auto i = 0; i < n; i++)
        {
            s.push_back(nums[i]);
            pref[i] = (nums[i] % p == 0) + (i > 0 ? pref[i - 1] : 0);
        }

        std::unordered_set<std::string_view> un;

        for (auto left = 0; left < n; left++)
        {
            for (auto right = left; right < n; right++)
            {
                const auto sum = pref[right] - (left > 0 ? pref[left - 1] : 0);

                if (sum <= k)
                {
                    un.insert(std::string_view(s).substr(left, right - left + 1));
                }
            }
        }

        return std::size(un);
    }
};