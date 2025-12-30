// https://leetcode.com/problems/last-remaining-integer-after-alternating-deletion-operations/description/

class Solution
{
public:
    long long lastInteger(long long n)
    {
        long long head = 1;
        long long tail = n;
        long long step = 1;
        bool from_left = true;

        while (n > 1)
        {
            if (!from_left && n % 2 == 0)
            {
                head += step;
            }

            from_left ^= true;
            step *= 2;
            n -= n / 2;
        }

        return head;
    }
};