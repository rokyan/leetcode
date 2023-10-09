// https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/description/

class Solution
{
public:
    long long minimumCost(std::string s)
    {
        const auto n = std::size(s);

        std::vector<std::vector<long long>> pdp(2, std::vector<long long>(n)), sdp(2, std::vector<long long>(n));

        for (auto i = 0; i < n; i++)
        {
            pdp[0][i] = s[i] == '0'
                ? (i > 0 ? pdp[0][i - 1] : 0)
                : i + 1 + (i > 0 ? pdp[1][i - 1] : 0);
            pdp[1][i] = s[i] == '1'
                ? (i > 0 ? pdp[1][i - 1] : 0)
                : i + 1 + (i > 0 ? pdp[0][i - 1] : 0);
        }

        for (auto i = static_cast<int>(n) - 1; i >= 0; i--)
        {
            sdp[0][i] = s[i] == '0'
                ? (i + 1 < n ? sdp[0][i + 1] : 0)
                : n - i + (i + 1 < n ? sdp[1][i + 1] : 0);
            sdp[1][i] = s[i] == '1'
                ? (i + 1 < n ? sdp[1][i + 1] : 0)
                : n - i + (i + 1 < n? sdp[0][i + 1] : 0);
        }

        auto res = std::min(sdp[0][0], sdp[1][0]);

        for (auto i = 0; i < n; i++)
        {
            res = std::min(res, pdp[0][i] + (i + 1 < n ? sdp[0][i + 1] : 0));
            res = std::min(res, pdp[1][i] + (i + 1 < n ? sdp[1][i + 1] : 0));
        }

        return res;
    }
};