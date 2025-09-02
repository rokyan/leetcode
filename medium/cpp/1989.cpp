// https://leetcode.com/problems/maximum-number-of-people-that-can-be-caught-in-tag/description/

class Solution
{
public:
    int catchMaximumAmountofPeople(const std::vector<int>& team, int dist)
    {
        const int n = std::size(team);

        std::vector<char> covered(n);

        auto last = 0;
        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            if (team[i] == 1)
            {
                while (last < n && (team[last] == 1 || team[last] == 0 && last < i - dist))
                {
                    last++;
                }

                if (last < n && last <= i + dist)
                {
                    res++;
                    last++;
                }
            }
        }

        return res;
    }
};