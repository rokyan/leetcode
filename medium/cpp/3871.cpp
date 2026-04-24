// https://leetcode.com/problems/count-commas-in-range-ii/description/

class Solution
{
public:
    long long countCommas(long long n)
    {
        long long cur = 1;
        int commas = 0;
        long long res = 0;

        while (true)
        {
            long long next = cur * 1000;

            if (next > n)
            {
                break;
            }

            res += commas * (next - cur);
            cur = next;
            commas++;
        }

        // std::cout << cur << " " << res << std::endl;

        res += commas * (n - cur + 1);

        return res;
    }
};

/*
23,234,567
...
23,000,000
...
10,000,000
...
1,000,000

1 .. 999
1,000 -> 99,999
1,000,000 -> 99,999,9999

*/