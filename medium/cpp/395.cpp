// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

class Solution
{
public:
    int longestSubstring(std::string s, int k)
    {
        const auto n = static_cast<int>(std::size(s));

        return solve(s, 0, n, k);
    }

private:
    static int solve(const std::string& s, int l, int r, int k)
    {
        if (r - l < k)
        {
            return 0;
        }

        std::array<int, 26> freq{ 0 };

        for (auto i = l; i < r; i++)
        {
            freq[s[i] - 'a']++;
        }

        auto br = -1;

        for (auto c = 0; c < 26; c++)
        {
            if (freq[c] > 0 && freq[c] < k)
            {
                br = c + 'a';
                break;
            }
        }

        if (br == -1)
        {
            return r - l;
        }

        auto ret = 0;

        for (auto i = l; i < r; )
        {
            while (i < r && s[i] == br)
            {
                i++;
            }

            if (i == r)
            {
                break;
            }

            auto next = i;

            while (next < r && s[next] != br)
            {
                next++;
            }

            ret = std::max(ret, solve(s, i, next, k));

            i = next;
        }

        return ret;
    }
};