// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

class Solution
{
public:
    bool mergeTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target)
    {
        std::vector<int> best(3);
        
        for (const auto& triplet : triplets)
        {
            bool matches = true;
            
            for (int i = 0; i < 3; i++)
            {
                if (triplet[i] > target[i])
                {
                    matches = false;
                }
            }
            
            if (matches)
            {
                for (int i = 0; i < 3; i++)
                {
                    best[i] = std::max(best[i], triplet[i]);
                }
            }
        }
        
        return best == target;
    }
};