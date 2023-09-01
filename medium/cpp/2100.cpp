// https://leetcode.com/problems/find-good-days-to-rob-the-bank/description/

class Solution
{
public:
    std::vector<int> goodDaysToRobBank(std::vector<int>& security, int time)
    {
        const auto n = std::size(security);

        std::vector<int> dpr(n);

        for (auto i = static_cast<int>(std::size(security)) - 2; i >= 0; i--)
        {
            if (security[i] <= security[i + 1])
            {
                dpr[i] = dpr[i + 1] + 1;
            }
        }

        std::vector<int> res;
        res.reserve(n);

        for (auto i = 0, l = 0; i < std::size(security); i++)
        {
            if (i > 0 && security[i] <= security[i - 1])
            {
                l++;
            }
            else
            {
                l = 0;
            }

            if (l >= time && dpr[i] >= time)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};