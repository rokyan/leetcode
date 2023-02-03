// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/

class Solution
{
public:
    long long dividePlayers(std::vector<int>& skill)
    {
        const auto sum = std::accumulate(std::begin(skill), std::end(skill), 0);
        const auto n = std::size(skill);

        if (sum % (n / 2))
        {
            return -1;
        }

        const auto tot = sum / (n / 2);

        auto res = 0LL;

        std::vector<int> cnt(1000 + 1);

        for (const auto e : skill)
        {
            cnt[e]++;
        }

        for (auto i = 0; i <= 1000; i++)
        {
            while (cnt[i] > 0)
            {
                if (cnt[tot - i] == 0)
                {
                    return -1;
                }

                res += i * (tot - i);

                cnt[i]--;
                cnt[tot - i]--;
            }
        }

        return res;
    }
};