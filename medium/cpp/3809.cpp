// https://leetcode.com/problems/best-reachable-tower/description/

class Solution
{
public:
    std::vector<int> bestTower(const std::vector<std::vector<int>>& towers,
        const std::vector<int>& center, int radius)
    {
        const auto getDist = [](const auto& lhs, const auto& rhs)
        {
            int dist = 0;

            for (auto d = 0; d < 2; d++)
            {
                dist += std::abs(lhs[d] - rhs[d]);
            }

            return dist;
        };

        int x = -1;
        int y = -1;
        int qf = -1;

        for (int i = 0; i < towers.size(); i++)
        {
            const int dist = getDist(towers[i], center);

            if (dist <= radius)
            {
                if (towers[i][2] > qf)
                {
                    x = towers[i][0];
                    y = towers[i][1];
                    qf = towers[i][2];
                }
                else if (towers[i][2] == qf)
                {
                    const bool compRes = towers[i][0] < x ||
                        towers[i][0] == x && towers[i][1] < y;
                    
                    if (compRes)
                    {
                        x = towers[i][0];
                        y = towers[i][1];
                        qf = towers[i][2];                        
                    }
                }
            }
        }

        return {x, y};
    }
};