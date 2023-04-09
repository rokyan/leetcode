// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/

class Solution
{
public:
    int maximumBags(std::vector<int>& capacity, std::vector<int>& rocks, int additionalRocks)
    {
        const auto n = std::size(capacity);

        std::vector<int> idx(n);

        std::iota(std::begin(idx), std::end(idx), 0);

        std::sort(std::begin(idx), std::end(idx), [&capacity, &rocks](auto idx1, auto idx2) {
            return capacity[idx1] - rocks[idx1] < capacity[idx2] - rocks[idx2];
        });

        auto res = 0;

        for (auto i : idx)
        {
            const auto d = capacity[i] - rocks[i];

            if (additionalRocks >= d)
            {
                additionalRocks -= d;
                res++;
            }
            else
            {
                break;
            }
        }

        return res;
    }
};