// https://leetcode.com/problems/apply-operations-to-make-string-empty/description/

class Solution
{
public:
    std::string lastNonEmptyString(std::string s)
    {
        const auto n = static_cast<int>(std::size(s));

        std::vector<int> cnt(26);

        for (auto i = 0; i < n; i++)
        {
            cnt[s[i] - 'a']++;
        }

        const auto times = *std::max_element(std::cbegin(cnt), std::cend(cnt));

        std::vector<bool> seen(26);

        std::string res;

        for (auto i = n - 1; i >= 0; i--)
        {
            if (!seen[s[i] - 'a'] && cnt[s[i] - 'a'] == times)
            {
                seen[s[i] - 'a'] = true;
                res.push_back(s[i]);
            }
        }

        std::reverse(std::begin(res), std::end(res));

        return res;
    }
};