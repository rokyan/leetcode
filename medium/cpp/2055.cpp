// https://leetcode.com/problems/plates-between-candles/

class Solution
{
public:
    std::vector<int> platesBetweenCandles(std::string s, std::vector<std::vector<int>>& queries)
    {
        const auto n = std::size(s);

        std::vector<int> pos;
        pos.reserve(n);

        for (auto i = 0; i < n; i++)
        {
            if (s[i] == '|')
            {
                pos.push_back(i);
            }
        }

        const auto q = std::size(queries);

        std::vector<int> res(q);

        for (auto i = 0; i < q; i++)
        {
            auto l = queries[i][0];
            auto r = queries[i][1];

            auto lpos = std::lower_bound(std::begin(pos), std::end(pos), l) - std::begin(pos);
            auto rpos = std::upper_bound(std::begin(pos), std::end(pos), r) - std::begin(pos) - 1;

            if (lpos < rpos)
            {
                res[i] = pos[rpos] - pos[lpos] - (rpos - lpos);
            }
        }

        return res;
    }
};