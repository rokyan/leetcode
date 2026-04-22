// https://leetcode.com/problems/count-smaller-elements-with-opposite-parity/description/

class Solution
{
private:
    class SegmentTree
    {
    public:
        SegmentTree(unsigned n)
            : n{n},
            tree(4 * n)
        {}

        int sum(unsigned l, unsigned r)
        {
            return sum(l, r, 1, 0, n - 1);
        }

        void upd(unsigned pos, int val)
        {
            upd(pos, val, 1, 0, n - 1);
        }

    private:
        int sum(unsigned l, unsigned r, unsigned v, unsigned tl, unsigned tr)
        {
            if (l == tl && r == tr)
            {
                return tree[v];
            }

            const unsigned tm = tl + (tr - tl) / 2;

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

        void upd(unsigned pos, int val, unsigned v, unsigned tl, unsigned tr)
        {
            if (tl == tr)
            {
                tree[v] = val;
                return;
            }

            const unsigned tm = tl + (tr - tl) / 2;

            if (pos <= tm)
            {
                upd(pos, val, v * 2, tl, tm);
            }
            else
            {
                upd(pos, val, v * 2 + 1, tm + 1, tr);
            }

            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    private:
        unsigned n;
        std::vector<int> tree;
    };

public:
    std::vector<int> countSmallerOppositeParity(const std::vector<int>& nums)
    {
        std::vector<std::pair<int, int>> numsWithPos(nums.size());

        const int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            numsWithPos[i] = {nums[i], i};
        }

        std::ranges::sort(numsWithPos);

        SegmentTree odd(n + 1), even(n + 1);

        std::vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            const auto [val, pos] = numsWithPos[i];

            if (val % 2 == 0)
            {
                res[pos] = odd.sum(pos, n - 1);
                even.upd(pos, 1);
            }
            else
            {
                res[pos] = even.sum(pos, n - 1);
                odd.upd(pos, 1);
            }
        }

        return res;
    }
};