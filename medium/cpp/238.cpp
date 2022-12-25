class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        const auto zeroes =
            std::count_if(std::begin(nums), std::end(nums), [](auto e) { return e == 0; });
        
        if (zeroes > 1)
        {
            return std::vector<int>(std::size(nums));
        }
        
        if (zeroes == 1)
        {
            const auto prod =
                std::accumulate(std::begin(nums), std::end(nums), 1,
                    [](auto acc, auto e) {
                        if (e != 0) {
                            return acc * e;
                        }

                        return acc;
                    }
                );
            
            const auto index = std::distance(std::begin(nums),
                 std::find_if(std::begin(nums), std::end(nums), [](auto e) { return e == 0; }));
            
            std::vector<int> prods(std::size(nums));
            prods[index] = prod;
            
            return prods;
        }
        
        const auto size = std::size(nums);
        std::vector<int> prods(size);
        
        prods[0] = 1;
        
        for (std::size_t i = 1; i < size; i++)
        {
            prods[i] = nums[i - 1] * prods[i - 1];
        }
        
        auto suff_prod = 1;
        auto index = static_cast<int>(size) - 1;
        
        while (index >= 0)
        {
            prods[index] *= suff_prod;
            suff_prod *= nums[index--];
        }
        
        return prods;
    }
};