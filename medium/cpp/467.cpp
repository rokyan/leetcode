// https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/

class Solution
{
public:
    int findSubstringInWraproundString(std::string s)
    {
        std::vector<int> longest(26);
        
        for (auto i = 0, next = 1; i < std::size(s); )
        {
            while (next < std::size(s) && (s[next - 1] - 'a' + 1) % 26 == s[next] - 'a')
            {
                next++;
            }

            const auto len = next - i;

            for (auto j = i, cnt = 0; j < next && cnt < 26; j++)
            {
                longest[s[j] - 'a'] = std::max(longest[s[j] - 'a'], len - cnt);
                cnt++;
            }

            i = next;
            next++;
        }

        auto res = 0;

        for (auto c = 0; c < 26; c++)
        {
            res += longest[c];
        }

        return res;
    }
};