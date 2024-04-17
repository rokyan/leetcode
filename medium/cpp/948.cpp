// https://leetcode.com/problems/bag-of-tokens/description/

class Solution
{
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power)
    {
        std::sort(std::begin(tokens), std::end(tokens));

        auto l = 0;
        auto r = static_cast<int>(std::size(tokens)) - 1;

        auto res = 0;
        auto cur = 0;

        while (l <= r)
        {
            auto moved = false;

            while (l <= r && power >= tokens[l])
            {
                power -= tokens[l++];
                cur++;
                moved = true;
            }

            res = std::max(res, cur);

            if (l < r && cur >= 1)
            {
                power += tokens[r--];
                cur--;
                moved = true;
            }

            if (!moved)
            {
                break;
            }
        } 

        return res;   
    }
};