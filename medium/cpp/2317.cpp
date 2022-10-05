// https://leetcode.com/problems/maximum-xor-after-operations/

class Solution
{
public:
    int maximumXOR(std::vector<int>& nums)
    {       
        return std::accumulate(std::begin(nums), std::end(nums), 0, [](auto init, auto e) {
            return init | e;
        });
    }
};