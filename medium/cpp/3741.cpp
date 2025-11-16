// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/

class Solution
{
public:
    int minimumDistance(const std::vector<int>& nums)
    {
        std::unordered_map<int, std::vector<int>> pos;

        int res = -1;

        auto upd = [](int& res, int val)
        {
            res = res == -1 ? val : std::min(res, val);
        };

        for (int i = 0; i < std::size(nums); i++)
        {
            auto& e = pos[nums[i]];

            if (std::size(e) < 2)
            {
                e.push_back(i);
            }
            else if (std::size(e) == 2)
            {
                e.push_back(i);
                upd(res, 2 * (e[2] - e[0]));
            }
            else
            {
                e[0] = e[1];
                e[1] = e[2];
                e[2] = i;
                upd(res, 2 * (e[2] - e[0]));
            }
        }

        return res;
    }
};