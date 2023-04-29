// https://leetcode.com/problems/orderly-queue/description/

class Solution
{
public:
    std::string orderlyQueue(std::string s, int k)
    {
        if (k == 1)
        {
            std::string res{ s };

            const auto n = std::size(s);

            for (auto times = 0; times < n; times++)
            {
                std::rotate(std::begin(s), std::begin(s) + 1, std::end(s));
                res = std::min(res, s);
            }

            return res;
        }

        std::sort(std::begin(s), std::end(s));

        return s;
    }
};