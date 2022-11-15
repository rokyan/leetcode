// https://leetcode.com/problems/watering-plants/

class Solution
{
public:
    int wateringPlants(std::vector<int>& plants, int capacity)
    {
        int n = 1;
        int acc = 0;
        
        for (std::size_t pos = 0; pos < std::size(plants); pos++)
        {
            if (plants[pos] + acc > capacity)
            {
                n++;
                acc = plants[pos];
            }
            else
            {
                acc += plants[pos];
            }
        }
        
        int result = 0;
        int len = 0;
        acc = 0;
        
        for (std::size_t pos = 0; pos < std::size(plants); pos++)
        {
            if (plants[pos] + acc > capacity)
            {
                result += (2 * n - 1) * len;
                n--;
                len = 1;
                acc = plants[pos];
            }
            else
            {
                acc += plants[pos];
                len++;
            }
        }
        
        result += len;
        
        return result;
    }
};