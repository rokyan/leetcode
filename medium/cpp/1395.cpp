// https://leetcode.com/problems/count-number-of-teams/

class Solution
{
public:
    int numTeams(std::vector<int>& rating)
    {
        int number_of_teams = 0;
        
        for (std::size_t i = 1; i + 1 < std::size(rating); i++)
        {
            int less_than = 0;
            int greater_than = 0;
            
            for (std::size_t j = 0; j < i; j++)
            {
                if (rating[j] < rating[i])
                {
                    less_than++;
                }
            }
            
            for (std::size_t j = i + 1; j < std::size(rating); j++)
            {
                if (rating[j] > rating[i])
                {
                    greater_than++;
                }
            }
            
            number_of_teams += less_than * greater_than;
            
            less_than = 0;
            greater_than = 0;
            
            for (std::size_t j = 0; j < i; j++)
            {
                if (rating[j] > rating[i])
                {
                    greater_than++;
                }
            }
            
            for (std::size_t j = i + 1; j < std::size(rating); j++)
            {
                if (rating[j] < rating[i])
                {
                    less_than++;
                }
            }
            
            number_of_teams += less_than * greater_than;
        }
        
        return number_of_teams;
    }
};