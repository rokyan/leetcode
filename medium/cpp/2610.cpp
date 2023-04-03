// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/

class Solution
{
public:
    std::vector<std::vector<int>> findMatrix(std::vector<int>& nums)
    {
        std::array<int, 201> cnt { 0 };

        for (auto num : nums)
        {
            cnt[num++];
        }

        std::vector<std::vector<int>> res;

        for (auto tot = 0; tot < std::size(nums); )
        {
            std::vector<int> row;

            for (auto num = 1; num <= 200; num++)
            {
                if (cnt[num] > 0)
                {
                    cnt[num]--;
                    row.push_back(num);
                    tot++;
                }
            }

            res.push_back(row);
        }

        return res;
    }
};