// https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution
{
public:
    int characterReplacement(std::string s, int k)
    {
        auto res = solve(s, k, 'A');

        for (auto c = 'B'; c <= 'Z'; c++)
        {
            res = std::max(res, solve(s, k, c));
        }

        return res;
    }

private:
    int solve(const std::string& s, int k, char c)
    {
        auto res = 0;

        for (auto r = 0, l = 0, d = 0; r < std::size(s); r++)
        {
            if (s[r] != c)
            {
                d++;
            }

            while (d == k + 1)
            {
                if (s[l] != c)
                {
                    d--;
                }

                l++;
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};