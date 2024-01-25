// https://leetcode.com/problems/avoid-flood-in-the-city/

class Solution
{
public:
    std::vector<int> avoidFlood(std::vector<int>& rains)
    {
        const auto n = std::size(rains);
        std::vector<int> res(n, -1);

        std::set<int> zeroes;
        std::unordered_map<int, int> pos;
        auto last = -1;

        for (auto i = 0; i < n; i++)
        {
            if (rains[i] == 0)
            {
                zeroes.insert(i);
            }
            else
            {
                last = rains[i];

                if (const auto it = pos.find(rains[i]); it != std::end(pos))
                {
                    const auto rit = zeroes.upper_bound(it->second);

                    if (rit == std::end(zeroes))
                    {
                        return {};
                    }

                    res[*rit] = it->first;
                    it->second = i;
                    zeroes.erase(rit);
                }
                else
                {
                    pos.insert({ rains[i], i });
                }
            }
        }

        if (!zeroes.empty())
        {
            if (last == -1)
            {
                return {};
            }

            for (auto pos : zeroes)
            {
                res[pos] = last;
            }
        }

        return res;
    }
};