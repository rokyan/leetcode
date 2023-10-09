// https://leetcode.com/problems/count-the-hidden-sequences/description/

class Solution
{
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper)
    {
        const auto n = std::size(differences);

        auto min_val = 0LL;
        auto max_val = 0LL;

        auto acc = 0LL;

        for (auto i = 0; i < n; i++)
        {
            acc += differences[i];

            min_val = std::min(min_val, acc);
            max_val = std::max(max_val, acc);
        }

        auto x = upper - lower + 1;
        auto y = max_val - min_val + 1;

        if (y > x)
        {
            return 0;
        }

        return x - y + 1;
    }
};