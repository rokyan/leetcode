// https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution
{
public:
    int equalSubstring(std::string s, std::string t, int maxCost)
    {
        auto res = 0;

        for (auto l = 0, r = 0, sum = 0; r < std::size(s); r++)
        {
            sum += std::abs(s[r] - t[r]);

            while (sum > maxCost)
            {
                sum -= std::abs(s[l] - t[l]);
                l++;
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};