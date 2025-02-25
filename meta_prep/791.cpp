class Solution
{
public:
    std::string customSortString(const std::string& order, const std::string& s)
    {
        std::array<int, 26> weight;
        weight.fill(27);

        for (auto i = 0; i < std::size(order); i++)
        {
            weight[order[i] - 'a'] = i;
        }

        auto sorted{s};

        std::sort(std::begin(sorted), std::end(sorted), [&weight](auto c1, auto c2) {
            return weight[c1 - 'a'] < weight[c2 - 'a'];
        });

        return sorted;
    }
};