class Solution
{
private:
    class SegmentTree
    {
    public:
        SegmentTree(int size)
            : size{size}
        {
            data.resize(4 * size);
        }

        int sum(int l, int r)
        {
            return sumInternal(l, r, 1, 0, size - 1);
        }

        void update(int pos)
        {
            updateInternal(pos, 1, 0, size - 1);
        }

    private:
        int sumInternal(int l, int r, int v, int tl, int tr)
        {
            if (l == tl && r == tr)
            {
                return data[v];
            }

            const int mid = tl + (tr - tl) / 2;

            if (r <= mid)
            {
                return sumInternal(l, r, v * 2, tl, mid);
            }

            if (l > mid)
            {
                return sumInternal(l, r, v * 2 + 1, mid + 1, tr);
            }

            return sumInternal(l, mid, v * 2, tl, mid)
                + sumInternal(mid + 1, r, v * 2 + 1, mid + 1, tr);
        }

        void updateInternal(int pos, int v, int tl, int tr)
        {
            if (tl == tr)
            {
                data[v]++;
                return;
            }

            const int mid = tl + (tr - tl) / 2;

            if (pos <= mid)
            {
                updateInternal(pos, v * 2, tl, mid);
            }
            else
            {
                updateInternal(pos, v * 2 + 1, mid + 1, tr);
            }

            data[v] = data[2 * v] + data[2 * v + 1];
        }

    private:
        std::vector<int> data;
        int size;
    };

public:
    std::vector<int> countSmaller(const std::vector<int>& nums)
    {
        SegmentTree tree(2 * 10001);

        const int n = std::size(nums);

        std::vector<int> res(n);

        for (int i = n - 1; i >= 0; i--)
        {
            const int val = nums[i] + 10000;
            res[i] = val > 0 ? tree.sum(0, val - 1) : 0;
            tree.update(val);
        }

        return res;
    }
};