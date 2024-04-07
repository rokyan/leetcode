// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

class Solution
{
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success)
    {
        const auto n = std::size(spells);
        const auto m = std::size(potions);

        std::vector<std::pair<int, int>> swi(n);

        for (auto i = 0; i < n; i++)
        {
            swi[i] = { spells[i], i };
        }

        std::sort(std::begin(swi), std::end(swi));

        std::sort(std::begin(potions), std::end(potions), std::greater<>{});

        std::vector<int> res(n);

        for (auto i = 0, j = 0; i < n; i++)
        {
            while (j < m && 1LL * swi[i].first * potions[j] >= success)
            {
                j++;
            }

            if (j > 0)
            {
                res[swi[i].second] = j;
            }
        }

        return res;
    }
};