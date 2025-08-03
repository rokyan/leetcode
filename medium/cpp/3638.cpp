// https://leetcode.com/problems/maximum-balanced-shipments/description/

class Solution
{
public:
    int maxBalancedShipments(const std::vector<int>& weight)
    {
        auto maxIdx = 0;
        auto res = 0;

        for (auto i = 1; i < std::size(weight); i++)
        {
            if (weight[i] < weight[maxIdx])
            {
                res++;
                maxIdx = i + 1;
            }
            else
            {
                maxIdx = i;
            }
        }

        return res;
    }
};