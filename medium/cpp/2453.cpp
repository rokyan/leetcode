// https://leetcode.com/problems/destroy-sequential-targets/description/

class Solution
{
public:
    int destroyTargets(std::vector<int>& nums, int space)
    {
        std::unordered_map<int, std::pair<int, int>> mp;

        for (auto num : nums)
        {
            if (auto it = mp.find(num % space); it != std::end(mp))
            {
                it->second.first = std::min(it->second.first, num);
                it->second.second++;
            }
            else
            {
                mp[num % space] = { num, 1 };
            }
        }

        auto res = 0;
        auto c = 0;

        for (const auto& e : mp)
        {
            if (e.second.second > c || e.second.second == c && (res == 0 || e.second.first < res))
            {
                res = e.second.first;
                c = e.second.second;
            }
        }

        return res;
    }
};