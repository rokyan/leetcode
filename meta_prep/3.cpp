class Solution
{
public:
    int lengthOfLongestSubstring(const std::string& s)
    {
        std::array<int, 256> cnt{0};

        const auto n = std::size(s);
        auto res = 0;

        for (auto l = 0, r = 0; r < n; r++)
        {
              cnt[s[r]]++;

            while (cnt[s[r]] == 2)
            {
                cnt[s[l++]]--;
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};