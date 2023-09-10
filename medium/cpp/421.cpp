// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

class Solution
{
public:  
    int findMaximumXOR(std::vector<int>& nums) 
    {
        auto res = 0;
        auto mask = 0;

        for (auto bit = 31; bit >= 0; bit--)
        {
            mask |= (1 << bit);

            std::unordered_set<int> probe;

            for (auto num : nums)
            {
                probe.insert(num & mask);
            }

            const auto next = res | (1 << bit);

            for (auto entry : probe)
            {
                const auto it = probe.find(entry ^ next);

                if (it != std::end(probe))
                {
                    res = next;
                    break;
                }
            }
        }

        return res;
    }
};