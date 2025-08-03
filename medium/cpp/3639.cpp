// https://leetcode.com/problems/minimum-time-to-activate-string/description/

class Solution
{
public:
    int minTime(const std::string& s, const std::vector<int>& order, int k)
    {
        const int n = std::size(s);

        const auto tot = calc(n);
        auto rem = tot;

        std::set<int> allPos{-1, n};

        for (auto t = 0; t < std::size(order); t++)
        {
            const auto pos = order[t];

            const auto it = allPos.insert(pos).first;
            const auto prevIt = std::prev(it);
            const auto nextIt = std::next(it);
            rem -= calc(*nextIt - *prevIt - 1);
            rem += calc(*nextIt - *it - 1);
            rem += calc(*it - *prevIt - 1);

            if (tot - rem >= k)
            {
                return t;
            }
        }

        return -1;
    }

private:
    long long calc(int x)
    {
        return 1LL * x * (x + 1) / 2;
    }
};