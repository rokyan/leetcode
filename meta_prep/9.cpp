class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        if (x % 10 == 0 && x > 0)
        {
            return false;
        }

        auto rev = 0LL;

        for (auto cx = x; cx > 0 && rev < x; cx /= 10)
        {
            rev = 10 * rev + cx % 10;
        }

        return rev == x;
    }
};