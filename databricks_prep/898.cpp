class Solution
{
public:
    int subarrayBitwiseORs(const std::vector<int>& arr)
    {
        std::array<int, 32> lastPos;
        lastPos.fill(-1);

        std::unordered_set<int> unique(std::cbegin(arr), std::cend(arr));
        std::map<int, std::vector<int>, std::greater<int>> m;

        for (auto i = 0; i < std::size(arr); i++)
        {
            m.clear();

            for (auto bit = 0; bit < 32; bit++)
            {
                if (!(arr[i] & (1 << bit)) && lastPos[bit] != -1)
                {
                    m[lastPos[bit]].push_back(bit);
                }
            }

            auto acc = 0;

            for (const auto& [_, bits] : m)
            {
                for (auto bit : bits)
                {
                    acc |= 1 << bit;
                }

                unique.insert(acc | arr[i]);
            }

            for (auto bit = 0; bit < 32; bit++)
            {
                if (arr[i] & (1 << bit))
                {
                    lastPos[bit] = i;
                }
            }
        }

        return std::size(unique);
    }
};