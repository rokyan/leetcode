class Solution
{
public:
    double myPow(double x, int n)
    {
        auto inv = false;
        auto nn = static_cast<long long>(n);

        if (nn < 0)
        {
            inv = true;
            nn *= -1;
        }

        double res = 1.0;

        while (nn > 0)
        {
            if (nn & 1)
            {
                res *= x;
                nn--;
            }
            else
            {
                x *= x;
                nn /= 2;
            }
        }

        if (inv)
        {
            res = 1.0 / res;
        }

        return res;
    }
};