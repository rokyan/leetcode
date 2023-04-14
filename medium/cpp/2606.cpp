// https://leetcode.com/problems/find-the-substring-with-maximum-cost/

class Solution
{
public:
    int maximumCostSubstring(std::string s, std::string chars, std::vector<int>& vals)
    {
        std::vector<int> char_to_val(26, -1001);

        for (auto i = 0; i < std::size(chars); i++)
        {
            const auto ord = chars[i] - 'a';
            char_to_val[ord] = vals[i];
        }

        auto min_on_pref = 0;
        auto res = 0;

        for (auto i = 0, sum = 0; i < std::size(s); i++)
        {
            const auto ord = s[i] - 'a';

            if (char_to_val[ord] == -1001)
            {
                sum += ord + 1;
            }
            else
            {
                sum += char_to_val[ord];
            }

            res = std::max(res, sum - min_on_pref);
            min_on_pref = std::min(min_on_pref, sum);
        }

        return res;
    }
};