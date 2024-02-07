// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

class Solution
{
public:
    int chalkReplacer(std::vector<int>& chalk, int k)
    {
        const auto tot = std::accumulate(std::cbegin(chalk), std::cend(chalk), 0LL);
        k %= tot;

        auto res = 0;

        while (k >= chalk[res])
        {
            k -= chalk[res++];
        }

        return res;
    }
};