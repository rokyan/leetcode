// https://leetcode.com/problems/maximum-points-after-enemy-battles/description/

class Solution
{
public:
    long long maximumPoints(std::vector<int>& enemyEnergies, int currentEnergy)
    {
        if (currentEnergy == 0)
        {
            return 0;
        }

        auto minEnergy = enemyEnergies.front();
        auto sum = 0LL;

        for (auto e : enemyEnergies)
        {
            sum += e;
            minEnergy = std::min(minEnergy, e);
        }

        if (currentEnergy < minEnergy)
        {
            return 0;
        }

        sum -= minEnergy;
        sum += currentEnergy;

        return sum / minEnergy;
    }
};