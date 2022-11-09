// https://leetcode.com/problems/boats-to-save-people/

class Solution
{
public:
    int numRescueBoats(std::vector<int>& people, int limit)
    {
        std::sort(std::begin(people), std::end(people));
        
        int left = 0;
        int right = std::size(people) - 1;
        
        int count = 0;
        
        while (left <= right)
        {
            const int rem = limit - people[right];
            
            if (left < right && rem >= people[left])
            {
                left++;
            }
            
            right--;
            count++;
        }
        
        return count;
    }
};