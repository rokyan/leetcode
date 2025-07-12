// https://leetcode.com/problems/minimum-threshold-for-inversion-pairs-count/description/

class Solution
{
private:
    class Tree
    {
    public:
        Tree(int n)
        {
            tree.resize(n);
        }

        void inc(int pos, int value)
        {
            for (; pos < std::size(tree); pos = pos | (pos + 1))
            {
                tree[pos] += value;
            }
        }

        int sum(int l, int r)
        {
            return sum(r) - sum(l - 1);
        }

    private:
        int sum(int r)
        {
            auto res = 0;

            for (; r >= 0; r = (r & (r + 1)) - 1)
            {
                res += tree[r];
            }

            return res;
        }

    private:
        std::vector<int> tree;
    };

public:
    int minThreshold(const std::vector<int>& nums, int k)
    {
        auto lo = 0;
        auto hi = 1000'000'000;

        const auto n = std::size(nums);

        std::vector<std::pair<int, int>> numsWithPos(n);

        for (auto i = 0; i < n; i++)
        {
            numsWithPos[i] = {nums[i], i};
        }

        std::ranges::sort(numsWithPos, std::greater<>{});

        auto res = -1;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            if (check(numsWithPos, mid, k))
            {
                res = mid;
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return res;
    }

private:
    bool check(const std::vector<std::pair<int, int>>& numsWithPos, int x, int k)
    {
        const auto n = std::size(numsWithPos);

        Tree tree(n);

        auto s = 0;

        for (auto l = 0, r = 0; r < n && s < k; r++)
        {
            while (numsWithPos[l].first - numsWithPos[r].first > x)
            {
                tree.inc(numsWithPos[l++].second, -1);
            }

            s += tree.sum(0, numsWithPos[r].second);
            tree.inc(numsWithPos[r].second, 1);
        }

        return s >= k;
    }
};