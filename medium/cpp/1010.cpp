// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/

class Solution
{
public:
    int numPairsDivisibleBy60(std::vector<int>& time)
    {
        std::array<int, 60> mod{ 0 };

        for (auto t : time)
        {
            mod[t % 60]++;
        }

        auto res = 0;

        res += 1LL * mod[0] * (mod[0] - 1) / 2;
        res += 1LL * mod[30] * (mod[30] - 1) / 2;

        for (auto i = 1; i < 30; i++)
        {
            res += mod[i] * mod[60 - i];
        }

        return res;
    }
};