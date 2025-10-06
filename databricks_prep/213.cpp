class Solution
{
private:
    using iter_type = std::vector<int>::const_iterator;
    
public:
    int rob(std::vector<int>& nums)
    {
        if (std::size(nums) == 1)
        {
            return nums.front();
        }
        
        return std::max(
            solve(++std::begin(nums), std::end(nums)),
            solve(std::begin(nums), --std::end(nums)));
    }
    
private:
    int solve(iter_type first, iter_type last)
    {
        if (first == last)
        {
            return 0;
        }
        
        auto taken = *first++;
        auto skipped = 0;
        
        while (first != last)
        {
            const auto last_taken = taken;
            
            taken = std::max(taken, skipped + *first++);
            skipped = last_taken;
        }
        
        return std::max(taken, skipped);
    }
};