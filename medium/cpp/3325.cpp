// https://leetcode.com/problems/count-substrings-with-k-frequency-characters-i/description/

class Solution
{
public:
    int numberOfSubstrings(const std::string& s, int k)
    {
        const auto n = std::size(s);

        std::array<int, 26> freq{ 0 };
        auto res = 0;

        auto check = [&freq, k]()
        {
            auto found = false;

            for (auto c = 0; c < 26 && !found; c++)
            {
                if (freq[c] >= k)
                {
                    found = true;
                }
            }

            return found;
        };

        for (auto l = 0, r = 0; l < n; l++)
        {
            while (r < n && !check())
            {
                freq[s[r++] - 'a']++;
            }

            if (check())
            {
                res += n - r + 1;
            }

            freq[s[l] - 'a']--;
        }

        return res;
    }
};