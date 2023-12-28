// https://leetcode.com/problems/range-addition/description/

class Solution
{
public:
    std::vector<int> getModifiedArray(int length, std::vector<std::vector<int>>& updates)
    {
        std::vector<int> res(length);

        for (const auto& up : updates)
        {
            res[up[0]] += up[2];

            if (up[1] + 1 < length)
            {
                res[up[1] + 1] -= up[2];
            }
        }

        for (auto i = 1; i < length; i++)
        {
            res[i] += res[i - 1];
        }
        
        return res;
    }
};