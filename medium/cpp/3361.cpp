// https://leetcode.com/problems/shift-distance-between-two-strings/description/

class Solution
{
public:
    long long shiftDistance(const std::string& s, const std::string& t,
        const std::vector<int>& nextCost, const std::vector<int>& previousCost)
    {
        const auto n = std::size(s);

        auto res = 0LL;

        for (auto i = 0; i < n; i++)
        {
            auto c = s[i];
            auto next = 0LL;

            while (c != t[i])
            {
                next += nextCost[c - 'a'];
                c = (c - 'a' + 1) % 26 + 'a';
            }

            c = s[i];
            auto prev = 0LL;

            while (c != t[i])
            {
                prev += previousCost[c - 'a'];
                c = (c - 'a' - 1 + 26) % 26 + 'a';
            }

            res += std::min(next, prev);
        }

        return res;
    }
};