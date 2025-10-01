// https://leetcode.com/problems/distinct-points-reachable-after-substring-removal/description/

class Solution
{
public:
    int distinctPoints(const std::string& s, int k)
    {
        if (k == 0)
        {
            return 0;
        }

        auto x = 0;
        auto y = 0;

        for (auto i = k; i < std::size(s); i++)
        {
            if (s[i] == 'U')
            {
                y++;
            }
            else if (s[i] == 'D')
            {
                y--;
            }
            else if (s[i] == 'L')
            {
                x--;
            }
            else
            {
                x++;
            }
        }

        std::set<std::pair<int, int>> un;
        un.emplace(x, y);

        auto curx = 0;
        auto cury = 0;

        for (auto i = 0; i + k < std::size(s); i++)
        {
            if (s[i] == 'U')
            {
                cury++;
            }
            else if (s[i] == 'D')
            {
                cury--;
            }
            else if (s[i] == 'L')
            {
                curx--;
            }
            else
            {
                curx++;
            }

            if (s[i + k] == 'U')
            {
                y--;
            }
            else if (s[i + k] == 'D')
            {
                y++;
            }
            else if (s[i + k] == 'L')
            {
                x++;
            }
            else
            {
                x--;
            }

            un.emplace(curx + x, cury + y);         
        }

        return std::size(un);
    }
};