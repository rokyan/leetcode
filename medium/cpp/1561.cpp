// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/

class Solution
{
public:
    int maxCoins(std::vector<int>& piles)
    {       
        std::sort(begin(piles), end(piles), std::greater<>());

        auto res = 0;
        auto n = static_cast<int>(std::size(piles)) / 3;
        auto pos = 1;
        
        while (n-- > 0)
        {
            res += piles[pos];
            pos += 2;
        }
        
        return res;
    }
};