// https://leetcode.com/problems/count-triplets-with-even-xor-set-bits-ii/description/

class Solution
{
public:
    long long tripletCount(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c)
    {
        auto go = [](const std::vector<int>& v)
        {
            std::vector<long long> c(2);

            for (auto e : v)
            {
                auto cnt = 0;

                for (auto bit = 0; bit < 32; bit++)
                {
                    cnt += ((1 << bit) & e) != 0;
                }

                c[cnt % 2]++;
            }

            return c;
        };

        auto vals = go(a);

        for (auto p : {&b, &c})
        {
            const auto n_vals = go(*p);
            vals =
            {
                vals[0] * n_vals[0] + vals[1] * n_vals[1], 
                vals[0] * n_vals[1] + vals[1] * n_vals[0]
            };
        }

        return vals[0];
    }
};