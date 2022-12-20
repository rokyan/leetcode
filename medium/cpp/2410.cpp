// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/

class Solution
{
public:
    int matchPlayersAndTrainers(std::vector<int>& players, std::vector<int>& trainers)
    {
        std::sort(std::begin(players), std::end(players));
        std::sort(std::begin(trainers), std::end(trainers));

        auto res = 0;

        for (auto player_pos = 0, trainer_pos = 0; player_pos < std::size(players); )
        {
            while (trainer_pos < std::size(trainers) && trainers[trainer_pos] < players[player_pos])
            {
                trainer_pos++;
            }

            if (trainer_pos == std::size(trainers))
            {
                break;
            }

            res++;

            player_pos++;
            trainer_pos++;
        }

        return res;
    }
};