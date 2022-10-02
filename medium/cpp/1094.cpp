// https://leetcode.com/problems/car-pooling/

class Solution
{
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity)
    {
        std::vector<int> acc(1000 + 1);
        
        for (const auto& trip : trips)
        {
            acc[trip[1]] += trip[0];
            acc[trip[2]] -= trip[0];
        }
        
        int cur = 0;
        
        for (int i = 0; i <= 1000; i++)
        {
            cur += acc[i];
            
            if (cur > capacity)
            {
                return false;
            }
        }
        
        return true;
    }
};