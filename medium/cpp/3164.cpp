// https://leetcode.com/problems/find-the-number-of-good-pairs-ii/description/

class Solution
{
public:
    long long numberOfPairs(const std::vector<int>& nums1, const std::vector<int>& nums2, int k)
    {
        std::unordered_map<int, int> freq;

        for (const auto num : nums2)
        {
            freq[num]++;
        }

        auto res = 0LL;

        for (auto num : nums1)
        {
            if (num % k != 0)
            {
                continue;
            }

            const auto divided = num / k;

            for (auto i = 1; i * i <= divided; i++)
            {
                if (divided % i == 0)
                {
                    res += freq[i] + (i == divided / i ? 0 : freq[divided / i]);
                }
            }
        }

        return res;
    }
};