// https://leetcode.com/problems/count-collisions-on-a-road/description/

class Solution
{
public:
    int countCollisions(std::string directions)
    {
        const auto stat = std::count(std::begin(directions), std::end(directions), 'S');

        auto non = 0;

        for (auto i = 0; i < std::size(directions); i++)
        {
            if (directions[i] != 'L')
            {
                break;
            }

            non++;
        }

        for (auto i = static_cast<int>(std::size(directions)) - 1; i >= 0; i--)
        {
            if (directions[i] != 'R')
            {
                break;
            }

            non++;
        }

        return std::size(directions) - stat - non;
    }
};