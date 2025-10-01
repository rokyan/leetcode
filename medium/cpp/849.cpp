// https://leetcode.com/problems/maximize-distance-to-closest-person/description/

class Solution
{
public:
    int maxDistToClosest(vector<int>& seats)
    {
        auto res = 0;

        const int n = std::size(seats);

        while (seats[res] == 0)
        {
            res++;
        }

        auto last = res;

        for (auto i = res; i < n; i++)
        {
            if (seats[i] == 1)
            {
                const auto len = i - last - 1;
                res = std::max(res, (len + 1) / 2);
                last = i;
            }
        }

        res = std::max(res, n - 1 - last);

        return res;
    }
};