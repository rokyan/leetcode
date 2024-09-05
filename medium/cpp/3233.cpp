// https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/description/

class Solution
{
public:
    int nonSpecialCount(int l, int r)
    {
        const auto upper_lim = static_cast<int>(std::sqrt(r)) + 2;

        std::vector<char> is_prime(upper_lim, true);
        is_prime[0] = is_prime[1] = false;

        auto spec = 0;

        for (auto i = 2; i * i <= r; i++)
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