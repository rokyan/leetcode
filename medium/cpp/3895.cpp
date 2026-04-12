// https://leetcode.com/problems/count-digit-appearances/description/

class Solution
{
public:
    int countDigitOccurrences(const std::vector<int>& nums, int digit)
    {
        int cnt = 0;

        for (const int num : nums)
        {
            cnt += count(num, digit);
        }

        return cnt;
    }

private:
    static int count(int x, int d)
    {
        int cnt = 0;

        while (x > 0)
        {
            if (x % 10 == d)
            {
                cnt++;
            }

            x /= 10;
        }

        return cnt;
    }
};