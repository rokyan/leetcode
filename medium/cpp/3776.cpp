// https://leetcode.com/problems/minimum-moves-to-balance-circular-array/description/

class Solution
{
public:
    long long minMoves(const std::vector<int>& balance)
    {
        const int n = std::size(balance);

        int pos = 0;

        while (pos < n && balance[pos] >= 0)
        {
            pos++;
        }

        if (pos == n)
        {
            return 0LL;
        }

        int take = n - 1;
        int left = pos;
        int right = pos;
        int d = 0;
        long long res = 0LL;
        int need = -balance[pos];

        while (take > 0)
        {
            d++;

            left = (left - 1 + n) % n;
            take--;

            const int v = std::min(need, balance[left]);
            need -= v;
            res += 1LL * d * v;

            if (need == 0)
            {
                break;
            }

            if (take == 0)
            {
                break;
            }

            right = (right + 1) % n;
            take--;

            const int vv = std::min(need, balance[right]);
            need -= vv;
            res += 1LL * d * vv;

            if (need == 0)
            {
                break;
            }
        }

        return need > 0 ? -1 : res;
    }
};