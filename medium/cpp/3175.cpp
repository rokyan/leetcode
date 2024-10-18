// https://leetcode.com/problems/find-the-first-player-to-win-k-games-in-a-row/description/

class Solution
{
public:
    int findWinningPlayer(std::vector<int>& skills, int k)
    {
        const auto n = std::size(skills);

        auto idx = 0;
        auto won = 0;

        for (auto i = 1; i < n; i++)
        {
            if (skills[idx] > skills[i])
            {
                won++;
            }
            else
            {
                idx = i;
                won = 1;
            }

            if (won == k)
            {
                return idx;
            }
        }

        return idx;
    }
};