// https://leetcode.com/problems/fruit-into-baskets/description/

class Solution
{
public:
    int totalFruit(std::vector<int>& fruits)
    {
        std::unordered_map<int, int> cnt;
        auto un = 0;
        auto res = 0;

        for (auto l = 0, r = 0; r < std::size(fruits); r++)
        {
            if (cnt[fruits[r]]++ == 0)
            {
                un++;
            }

            while (un == 3)
            {
                if (cnt[fruits[l++]]-- == 1)
                {
                    un--;
                }
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};