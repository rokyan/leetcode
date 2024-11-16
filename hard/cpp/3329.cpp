// https://leetcode.com/problems/count-substrings-with-k-frequency-characters-ii/description/

class Solution
{
public:
    long long numberOfSubstrings(const std::string& s, int k)
    {
        const auto n = std::size(s);

        std::array<int, 26> freq{ 0 };
        auto has = false;
        auto res = 0LL;

        for (auto l = 0, r = 0; l < n; l++)
        {
            while (r < n && !has)
            {
                if (++freq[s[r] - 'a'] == k)
                {
                    has = true;
                }

                r++;
            }

            if (has)
            {
                res += n - r + 1;
            }
            else
            {
                break;
            }

            if (freq[s[l] - 'a']-- == k)
            {
                has = false;
            }
        }

        return res;
    }
};