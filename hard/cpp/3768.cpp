// https://leetcode.com/problems/minimum-inversion-count-in-subarrays-of-fixed-length/description/

class Solution
{
private:
    class segment_tree final
    {
    public:
        segment_tree(int size)
            : size{size}
            , tree(4 * size)
        {}

        int sum(int l, int r)
        {
            return sum_impl(l, r, 1, 0, size - 1);
        }

        void inc(int pos)
        {
            add(pos, 1, 1, 0, size - 1);
        }

        void dec(int pos)
        {
            add(pos, -1, 1, 0, size - 1);
        }

    private:
        int sum_impl(int l, int r, int v, int tl, int tr)
        {
            if (l == tl && r == tr)
            {
                return tree[v];
            }

            const int mid = tl + (tr - tl) / 2;

            if (r <= mid)
            {
                return sum_impl(l, r, v * 2, tl, mid);
            }

            if (l > mid)
            {
                return sum_impl(l, r, v * 2 + 1, mid + 1, tr);
            }

            return sum_impl(l, mid, v * 2, tl, mid)
                + sum_impl(mid + 1, r, v * 2 + 1, mid + 1, tr);
        }

        void add(int pos, int value, int v, int tl, int tr)
        {
            if (tl == tr)
            {
                tree[v] += value;
                return;
            }

            const int mid = tl + (tr - tl) / 2;

            if (pos <= mid)
            {
                add(pos, value, v * 2, tl, mid);
            }
            else
            {
                add(pos, value, v * 2 + 1, mid + 1, tr);
            }

            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    
    private:
        int size;
        std::vector<int> tree;
    };

public:
    long long minInversionCount(std::vector<int>& nums, int k)
    {
        const int max_val = remap(nums);

        segment_tree tree{max_val + 1};

        long long cur = 0LL;

        for (int i = 0; i < k; i++)
        {
            cur += tree.sum(nums[i] + 1, max_val);
            tree.inc(nums[i]);
        }

        long long res = cur;

        const int n = std::size(nums);

        for (int i = k; i < n; i++)
        {
            cur -= tree.sum(0, nums[i - k] - 1);
            tree.dec(nums[i - k]);
            cur += tree.sum(nums[i] + 1, max_val);
            tree.inc(nums[i]);
            res = std::min(res, cur);
        }

        return res;
    }

private:
    int remap(std::vector<int>& nums)
    {
        std::map<int, int> mapper;

        for (int num : nums)
        {
            mapper[num] = 0;
        }

        int to = 1;

        for (auto& [key, value] : mapper)
        {
            value = to++;
        }

        for (int& num : nums)
        {
            num = mapper[num];
        }

        return to;
    }
};