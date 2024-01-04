// https://leetcode.com/problems/h-index-ii/description/

class Solution
{
public:
    int hIndex(std::vector<int>& citations)
    {
        std::array<int, 1000 + 1> cnt{ 0 };

        for (auto c : citations)
        {
            cnt[std::min(c, 1000)]++;
        }

        for (auto i = 1000, tot = 0; i >= 0; i--)
        {
            tot += cnt[i];

            if (tot >= i)
            {
                return i;
            }
        }

        return 0;
    }
};