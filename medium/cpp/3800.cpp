// https://leetcode.com/problems/minimum-cost-to-make-two-binary-strings-equal/description/

class Solution
{
public:
    long long minimumCost(const std::string& s, const std::string& t,
        int flipCost, int swapCost, int crossCost)
    {
        int x = 0;
        int y = 0;

        const int n = std::size(s);

        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                if (s[i] == '0')
                {
                    x++;
                }
                else
                {
                    y++;
                }
            }
        }

        int mv = std::min(x, y);

        const long long c1 = 1LL * flipCost * (x + y);
        const long long c2 = 1LL * swapCost * mv + 1LL * (x + y - 2 * mv) * flipCost;

        const int d = std::abs(x - y);
        long long c3 = 1LL * crossCost * (d / 2);

        if (d / 2 > 0)
        {
            if (x > y)
            {
                x -= d / 2;
                y += d / 2;
            }
            else
            {
                x += d / 2;
                y -= d / 2;
            }
        }

        mv = std::min(x, y);
        c3 += 1LL * swapCost * mv + 1LL * (x + y - 2 * mv) * flipCost;

        return std::min({c1, c2, c3});
    }
};