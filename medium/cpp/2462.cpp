// https://leetcode.com/problems/total-cost-to-hire-k-workers/description/

class Solution
{
private:
    using pii = std::pair<int, int>;

public:
    long long totalCost(std::vector<int>& costs, int k, int candidates)
    {
        const auto n = static_cast<int>(std::size(costs));

        std::set<pii> ls, rs;

        auto lp = 0;

        for (auto i = 0; i < candidates; i++)
        {
            ls.insert({costs[lp], lp++});
        }

        ls.insert({1e9, -1});

        auto rp = n - 1;

        for (auto i = 0; i < candidates; i++)
        {
            rs.insert({costs[rp], rp--});
        }

        rs.insert({1e9, -1});

        auto res = 0LL;

        while (k--)
        {
            const auto lv = *std::begin(ls);
            const auto rv = *std::begin(rs);

            if (lv.first <= rv.first)
            {
                ls.erase(std::begin(ls));
                res += lv.first;

                if (const auto it = rs.find(lv); it != std::end(rs))
                {
                    rs.erase(it);
                }

                if (lp <= rp)
                {
                    ls.insert({costs[lp], lp++});
                }
            }
            else
            {
                rs.erase(std::begin(rs));
                res += rv.first;

                if (const auto it = ls.find(rv); it != std::end(ls))
                {
                    ls.erase(it);
                }

                if (lp <= rp)
                {
                    rs.insert({costs[rp], rp--});
                }
            }
        }

        std::cout << "#" << std::endl;

        return res;
    }
};