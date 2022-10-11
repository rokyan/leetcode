// https://leetcode.com/problems/maximum-ice-cream-bars/

class Solution
{
public:
    int maxIceCream(std::vector<int>& costs, int coins)
    {
        std::sort(std::begin(costs), std::end(costs));
        
        int counter = 0;
        
        for (auto cost : costs)
        {
            if (cost > coins)
            {
                break;
            }
            
            counter++;
            
            coins -= cost;
        }
        
        return counter;
    }
};