// https://leetcode.com/problems/create-components-with-same-value/description/

class Solution
{
public:
    int componentValue(std::vector<int>& nums, std::vector<std::vector<int>>& edges)
    {
        const auto n = std::size(edges) + 1;

        std::vector<std::vector<int>> g(n, std::vector<int>());

        for (const auto& edge : edges)
        {
            const auto u = edge[0];
            const auto v = edge[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        std::vector<std::vector<int>> levels;

        std::queue<std::pair<int, int>> q;
        q.push({ 0, 0 });

        std::vector<int> p(n, -1);
        p[0] = 0;

        while (!q.empty())
        {
            const auto entry = q.front();
            q.pop();
            
            if (entry.second == std::size(levels))
            {
                levels.push_back({});
            }

            levels[entry.second].push_back(entry.first);

            for (const auto to : g[entry.first])
            {
                if (p[to] == -1)
                {
                    p[to] = entry.first;
                    q.push({ to, entry.second + 1 });
                }
            }
        }

        const auto tot = std::accumulate(std::begin(nums), std::end(nums), 0);

        auto res = 0;

        for (auto target = 1; target * target <= tot; target++)
        {
            if (tot % target == 0)
            {
                res = std::max(res, solve(levels, p, nums, target));
                
                if (tot / target != target)
                {
                    res = std::max(res, solve(levels, p, nums, tot / target));
                }
            }
        }

        return res;
    }

private:
    int solve(const std::vector<std::vector<int>>& levels, const std::vector<int>& p, std::vector<int> nums, int target)
    {
        auto cnt = 0;

        for (auto i = std::size(levels) - 1; i > 0; i--)
        {
            for (const auto v : levels[i])
            {
                if (nums[v] > target)
                {
                    return 0;
                }
                else if (nums[v] == target)
                {
                    cnt++;
                }
                else if (nums[v] < target)
                {
                    nums[p[v]] += nums[v];
                }
            }
        }

        if (nums[0] != target)
        {
            return 0;
        }

        return cnt;
    }
};