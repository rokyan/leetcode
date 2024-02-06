// https://leetcode.com/problems/minimum-health-to-beat-game/

class Solution
{
public:
    long long minimumHealth(vector<int>& damage, int armor)
    {
        auto s = std::accumulate(std::cbegin(damage), std::cend(damage), 0LL);

        auto res = s + 1;

        for (auto d : damage)
        {
            if (armor >= d)
            {
                res = std::min(res, s - d + 1);
            }
            else
            {
                res = std::min(res, s - armor + 1);
            }
        }

        return res;
    }
};