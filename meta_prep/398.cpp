class Solution
{
public:
    Solution(const std::vector<int>& nums)
        : gen{std::random_device{}()}
    {
        for (auto i = 0; i < std::size(nums); i++)
        {
            pos[nums[i]].push_back(i);
        }
    }
    
    int pick(int target)
    {
        const auto& pos_for_target = pos[target];
        std::uniform_int_distribution<> distrib(0, std::size(pos_for_target) - 1);
        return pos_for_target[distrib(gen)];
    }

private:
    std::unordered_map<int, std::vector<int>> pos;
     std::mt19937 gen;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */