// https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/description/

class Solution
{
private:
    static constexpr auto upper_lim = 100000;

public:
    int nonSpecialCount(int l, int r)
    {
        std::vector<char> is_prime(upper_lim, true);
        is_prime[0] = is_prime[1] = false;

        auto spec = 0;

        for (auto i = 2; i < upper_lim && i * i <= r; i++)
        {
            if (is_prime[i])
            {
                for (auto j = i * i; j < upper_lim; j += i)
                {
                    is_prime[j] = false;
                }

                if (i * i >= l && i * i <= r)
                {
                    spec++;
                }
            }
        }

        return r - l + 1 - spec;
    }
};