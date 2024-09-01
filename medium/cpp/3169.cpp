// https://leetcode.com/problems/count-days-without-meetings/description/

class Solution
{
public:
    int countDays(int days, std::vector<std::vector<int>>& meetings)
    {
        std::map<int, int> cnt;

        for (const auto& m : meetings)
        {
            cnt[m[0]]++;
            cnt[m[1] + 1]--;
        }

        auto last = 1;
        auto res = 0;
        auto balance = 0;

        for (const auto& e : cnt)
        {
            balance += e.second;

            if (balance == 0)
            {
                last = e.first;
            }
            else if (last > 0)
            {
                res += e.first - last;
                last = -1;
            }
        }

        if (last != -1 && last <= days)
        {
            res += days - last + 1;
        }

        return res;
    }
};