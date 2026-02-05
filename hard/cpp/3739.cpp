// https://leetcode.com/problems/count-subarrays-with-majority-element-ii/description/

class Solution
{
private:
    class SegmentTree final
    {
    public:
        SegmentTree(int n)
            : n{n}
            , data(4 * n)
        {}

        int sum(int l, int r)
        {
            return sum(l, r, 1, 0, n - 1);
        }

        void inc(int pos)
        {
            inc(pos, 1, 0, n - 1);
        }

    private:
        int sum(int l, int r, int v, int tl, int tr)
        {
            if (l == tl && r == tr)
            {
                return data[v];
            }

            const int tm = (tl + tr) / 2;

            if (r <= tm)
            {
                return sum(l, r, v * 2, tl, tm);
            }

            if (l > tm)
            {
                return sum(l, r, v * 2 + 1, tm + 1, tr);
            }

            return sum(l, tm, v * 2, tl, tm) + sum(tm + 1, r, v * 2 + 1, tm + 1, tr);
        }

        void inc(int pos, int v, int tl, int tr)
        {
            if (tl == tr)
            {
                data[v]++;
                return;
            }

            const int tm = (tl + tr) / 2;

            if (pos <= tm)
            {
                inc(pos, v * 2, tl, tm);
            }
            else
            {
                inc(pos, v * 2 + 1, tm + 1, tr);
            }

            data[v] = data[v * 2] + data[v * 2 + 1];
        }

    private:
        int n;
        std::vector<int> data;
    };

public:
    long long countMajoritySubarrays(const std::vector<int>& nums, int target)
    {
        const int n = nums.size();

        SegmentTree tree{2 * n + 1};

        int ps = 0;
        long long res = 0LL;

        tree.inc(n);

        for (int i = 0; i < n; i++)
        {
            ps += (nums[i] == target) ? 1 : -1;
            res += tree.sum(0, std::max(0, ps - 1 + n));
            tree.inc(ps + n);
        }

        return res;
    }
};

// p - x > 0, x < p