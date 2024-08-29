// https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/description/

class Solution
{
public:
    std::vector<int> occurrencesOfElement(std::vector<int>& nums, std::vector<int>& queries, int x)
    {
        std::vector<int> pos;
        pos.reserve(std::size(nums));

        for (auto i = 0; i < std::size(nums); i++)
        {
            if (nums[i] == x)
            {
                pos.push_back(i);
            }
        }

        std::vector<int> res;
        res.reserve(std::size(queries));

        for (auto query : queries)
        {
            if (query > std::size(pos))
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(pos[query - 1]);
            }
        }

        return res;
    }
};