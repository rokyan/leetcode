// https://leetcode.com/problems/smallest-all-ones-multiple/description/

class Solution
{
public:
    int minAllOneMultiple(int k)
    {
        int rem = 1;
        int cnt = 1;

        std::vector<char> seen(k);
        seen[1] = 0;

        for (;;)
        {
            cnt++;
            rem = (10 * rem + 1) % k;

            if (rem == 0)
            {
                return cnt;
            }

            if (seen[rem])
            {
                return -1;
            }

            seen[rem] = true;
        }

        return -1;
    }
};