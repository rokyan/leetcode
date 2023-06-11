// https://leetcode.com/problems/watering-plants-ii/description/

class Solution
{
public:
    int minimumRefill(std::vector<int>& plants, int capacityA, int capacityB)
    {
        const auto n = static_cast<int>(std::size(plants));

        auto res = 0;

        auto valA = capacityA;
        auto valB = capacityB;

        auto left = 0;
        auto right = n - 1;

        while (left <= right)
        {
            if (left == right)
            {
                if (valA >= valB)
                {
                    if (valA < plants[left])
                    {
                        res++;
                        valA = capacityA;
                    }

                    valA -= plants[left++];
                }
                else
                {
                    if (valB < plants[right])
                    {
                        res++;
                        valB = capacityB;
                    }

                    valB -= plants[right--];                
                }
            }
            else
            {
                if (valA < plants[left])
                {
                    res++;
                    valA = capacityA;
                }

                valA -= plants[left++];

                if (valB < plants[right])
                {
                    res++;
                    valB = capacityB;
                }

                valB -= plants[right--];
            }
        }

        return res;
    }
};