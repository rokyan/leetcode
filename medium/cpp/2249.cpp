// https://leetcode.com/problems/count-lattice-points-inside-a-circle/description/

class Solution
{
public:
    int countLatticePoints(std::vector<std::vector<int>>& circles)
    {
        auto res = 0;

        for (auto x = 0; x <= 200; x++)
        {
            for (auto y = 0; y <= 200; y++)
            {
                for (const auto& c : circles)
                {
                    if (sq(x - c[0]) + sq(y - c[1]) <= sq(c[2]))
                    {
                        res++;
                        break;
                    }
                }
            }
        }

        return res;
    }

private:
    int sq(int x)
    {
        return x * x;
    }
};