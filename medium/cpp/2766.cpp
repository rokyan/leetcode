// https://leetcode.com/problems/relocate-marbles/description/

class Solution
{
public:
    std::vector<int> relocateMarbles(std::vector<int>& nums, std::vector<int>& moveFrom, std::vector<int>& moveTo)
    {
        std::set<int> s(std::begin(nums), std::end(nums));

        for (auto i = 0; i < std::size(moveFrom); i++)
        {
            s.erase(moveFrom[i]);
            s.insert(moveTo[i]);
        }

        return std::vector<int>(std::begin(s), std::end(s));
    }
};