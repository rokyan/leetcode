// https://leetcode.com/problems/largest-palindromic-number/description/

class Solution
{
public:
    std::string largestPalindromic(std::string num)
    {
        std::vector<int> cnt(10);

        for (auto c : num)
        {
            cnt[c - '0']++;
        }

        std::string acc;

        for (auto d = 9; d >= 1; d--)
        {
            const auto take = cnt[d] >> 1;

            if (take > 0)
            {
                acc += std::string(take, '0' + d);
            }

            cnt[d] -= take * 2;
        }

        if (!acc.empty())
        {
           const auto take = cnt[0] >> 1;

            if (take > 0)
            {
                acc += std::string(take, '0');
            }

            cnt[0] -= take * 2;
        }

        std::string res = acc;

        for (auto d = 9; d >= 0; d--)
        {
            if (cnt[d] > 0)
            {
                res.push_back('0' + d);
                cnt[d]--;
                break;
            }
        }

        std::reverse(std::begin(acc), std::end(acc));
        res += acc;

        return res;
    }
};