// https://leetcode.com/problems/complete-prime-number/description/

class Solution
{
public:
    bool completePrime(int num)
    {
        if (!isPrime(num))
        {
            return false;
        }

        for (int pref = num / 10, suff = num % 10, b = 10; pref != 0; )
        {
            if (!isPrime(pref) || !isPrime(suff))
            {
                return false;
            }

            suff = b * (pref % 10) + suff;
            pref /= 10;
            b *= 10;
        }

        return true;
    }

private:
    bool isPrime(int num)
    {
        if (num <= 1)
        {
            return false;
        }

        for (int d = 2; d * d <= num; d++)
        {
            if (num % d == 0)
            {
                return false;
            }
        }

        return true;
    }
};