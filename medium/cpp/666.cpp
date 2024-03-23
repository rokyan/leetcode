// https://leetcode.com/problems/path-sum-iv/description/

class Solution
{
public:
    int pathSum(std::vector<int>& nums)
    {
        const auto get_level = [](const int num) { return num / 100; };
        const auto get_pos = [](const int num) { return (num % 100) / 10; };

        std::unordered_map<int, int> parent;

        const auto n = std::size(nums);

        std::vector<bool> leaf(n, true);

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                if (get_level(nums[i]) + 1 == get_level(nums[j]) && get_pos(nums[i]) == (get_pos(nums[j]) + 1) / 2)
                {
                    parent[nums[j]] = nums[i];
                    leaf[i] = false;
                }
            }
        }

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            if (leaf[i])
            {
                auto num = nums[i];
                res += num % 10;
                auto it = parent.find(num);

                while (it != std::end(parent))
                {
                    num = it->second;
                    res += num % 10;
                    it = parent.find(num);
                }
            }
        }

        return res;
    }
};