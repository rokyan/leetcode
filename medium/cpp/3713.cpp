// https://leetcode.com/problems/longest-balanced-substring-i/description/

class Solution
{
public:
    int longestBalanced(const std::string& s)
    {
        std::array<int, 26> freq;

        const int n = std::size(s);

        int res = 0;

        for (int l = 0; l < n; l++)
        {
            freq.fill(0);

            for (int r = l; r < n; r++)
            {
                const auto value = ++freq[s[r] - 'a'];
                bool valid = true;

                for (int c = 0; c < 26; c++)
                {
                    if (freq[c] > 0 && freq[c] != value)
                    {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                {
                    res = std::max(res, r - l + 1);
                }
            }
        }

        return res;
    }
};