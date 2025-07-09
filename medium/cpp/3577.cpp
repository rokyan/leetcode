// https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int countPermutations(vector<int>& complexity)
    {
        const auto n = std::size(complexity);

        auto res = 1;

        for (auto i = 1; i < n; i++)
        {
            if (complexity[i] <= complexity[0])
            {
                return 0;
            }

            res = 1LL * res * i % mod;
        }

        return res;
    }
};