// https://leetcode.com/problems/shuffle-an-array/description/

class Solution
{  
public:
    Solution(std::vector<int> nums)
        : gen(rd())
        , dis(0.0, 1.0)
    {
        init = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset()
    {
        return init;
    }
    
    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle()
    {
        auto shuffled = init;
        
        for (auto i = static_cast<int>(std::size(shuffled)) - 1; i >= 0; i--)
        {
            const auto idx = static_cast<std::size_t>(dis(gen) * (i + 1));
            std::swap(shuffled[i], shuffled[idx]);
        }
        
        return shuffled;
    }

private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
    std::vector<int> init;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */