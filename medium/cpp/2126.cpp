
// https://leetcode.com/problems/destroying-asteroids/

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids)
    {
        std::sort(std::begin(asteroids), std::end(asteroids));
        
        long long sum = mass;
        
        for (std::size_t i = 0; i < std::size(asteroids); i++)
        {
            if (asteroids[i] > sum)
            {
                return false;
            }
            
            sum += asteroids[i];
        }
        
        return true;
    }
};