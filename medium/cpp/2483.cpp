// https://leetcode.com/problems/minimum-penalty-for-a-shop/description/

class Solution
{
public:
    int bestClosingTime(std::string customers)
    {
        auto y_tot = std::count(std::begin(customers), std::end(customers), 'Y');
        auto n_tot = 0;

        auto res = y_tot + n_tot;
        auto pos = 0;

        for (auto i = 0; i < std::size(customers); i++)
        {
            y_tot -= customers[i] == 'Y';
            n_tot += customers[i] == 'N';

            auto cur = y_tot + n_tot;

            if (cur < res)
            {
                res = cur;
                pos = i + 1;
            }
        }

        return pos;
    }
};