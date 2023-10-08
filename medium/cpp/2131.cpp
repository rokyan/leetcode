// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/

class Solution
{
public:
    int longestPalindrome(std::vector<std::string>& words)
    {
        std::unordered_map<std::string, int> cnt;

        for (auto&& word : words)
        {
            cnt[word]++;
        }

        auto res = 0;

        for (auto&& entry : cnt)
        {
            if (entry.first[0] < entry.first[1])
            {
                const std::string rev{ entry.first[1], entry.first[0] };

                if (const auto it = cnt.find(rev); it != std::end(cnt))
                {
                    res += std::min(entry.second, it->second) * 4;
                }
            }
            else if (entry.first[0] == entry.first[1])
            {
                if (entry.second % 2 == 1 && res % 4 == 0)
                {
                    res += 2;
                }

                res += entry.second / 2 * 4;
            }
        }

        return res;
    }
};