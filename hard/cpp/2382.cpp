// https://leetcode.com/problems/maximum-segment-sum-after-removals/description/

class Solution
{
public:
    std::vector<long long> maximumSegmentSum(std::vector<int>& nums, std::vector<int>& removeQueries)
    {
        const auto n = std::size(nums);

        std::vector<bool> used(n);

        for (auto q : removeQueries)
        {
            used[q] = true;
        }

        init(n, nums);

        auto cur = 0LL;

        for (auto i = 0; i < n; i++)
        {
            if (!used[i] && (i > 0 && !used[i - 1]))
            {
                cur = std::max(cur, sum[un(i, i - 1)]);
            }
        }

        std::vector<long long> res(std::size(removeQueries));

        const auto q_tot = static_cast<int>(std::size(removeQueries));

        for (auto i = q_tot - 1; i >= 0; i--)
        {
            const auto pos = removeQueries[i];

            res[i] = cur;

            used[pos] = false;

            cur = std::max<long long>(cur, nums[pos]);
            
            if (pos > 0 && !used[pos - 1])
            {
                cur = std::max(cur, sum[un(pos - 1, pos)]);
            }

            if (pos + 1 < q_tot && !used[pos + 1])
            {
                cur = std::max(cur, sum[un(pos + 1, pos)]);
            }
        }

        return res;
    }

private:
    void init(int n, const std::vector<int>& nums)
    {
        parent.resize(n);
        size.resize(n);
        sum.resize(n);

        for (auto i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
            sum[i] = nums[i];
        }
    }

    int find(int v)
    {
        if (v == parent[v])
        {
            return v;
        }

        return v = find(parent[v]);
    }

    int un(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u == v)
        {
            return u;
        }

        if (size[u] > size[v])
        {
            size[u] += size[v];
            parent[v] = u;
            sum[u] += sum[v];
            return u;
        }
        else
        {
            size[v] += size[u];
            parent[u] = v;
            sum[v] += sum[u];
            return v;
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> size;
    std::vector<long long> sum;
};