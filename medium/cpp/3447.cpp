// https://leetcode.com/problems/assign-elements-to-groups-with-constraints/description/

class Solution
{
public:
    std::vector<int> assignElements(const std::vector<int>& groups, const std::vector<int>& elements)
    {
        std::unordered_map<int, int> eToIdx;

        for (auto i = 0; i < std::size(elements); i++)
        {
            if (eToIdx.count(elements[i]) == 0)
            {
                eToIdx[elements[i]] = i;
            }
        }

        std::vector<int> res(std::size(groups), -1);

        for (auto i = 0; i < std::size(groups); i++)
        {
            const auto value = groups[i];

            for (auto div = 1; div * div <= value; div++)
            {
                if (value % div == 0)
                {
                    if (const auto it = eToIdx.find(div); it != std::cend(eToIdx))
                    {
                        res[i] = res[i] == -1 ? it->second : std::min(res[i], it->second);
                    }

                    if (div == value / div)
                    {
                        continue;
                    }

                    if (const auto it = eToIdx.find(value / div); it != std::cend(eToIdx))
                    {
                        res[i] = res[i] == -1 ? it->second : std::min(res[i], it->second);
                    }
                }
            }
        }

        return res;
    }
};