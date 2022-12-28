// https://leetcode.com/problems/number-of-boomerangs/description/

class Solution
{
public:  
    int numberOfBoomerangs(std::vector<std::vector<int>>& points)
    {
        auto res = 0;       
        
        for (auto i = 0; i < std::size(points); ++i)
        {
            std::unordered_map<int, int> counter;
            
            for (auto j = 0; j < std::size(points); ++j)
            {
                if (i != j)
                {
                    counter[sq(points[i][0] - points[j][0]) + sq(points[i][1] - points[j][1])]++;
                }
            }
            
            for (auto&& entry : counter)
            {
                if (entry.second > 1)
                {
                    res += (entry.second - 1) * entry.second;
                }
            }
        }
        
        return res;
    }

private:
    int sq(int x)
    {
        return x * x;
    }
};