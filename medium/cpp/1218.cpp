// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/

class Solution
{
public:
    int longestSubsequence(std::vector<int>& arr, int difference)
    {
        std::unordered_map<int, int> cnt;

        auto res = 1;

        for (auto e : arr)
        {
            if (const auto it = cnt.find(e - difference); it != std::end(cnt))
            {
                const auto upd = std::max(cnt[e], it->second + 1);
                cnt[e] = upd;
                res = std::max(res, upd);
            }
            else
            {
                cnt[e] = 1;
            }
        }

        return res;
    }
};