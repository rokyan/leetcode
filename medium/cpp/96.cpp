// https://leetcode.com/problems/unique-binary-search-trees/description/

class Solution
{
public:
    int numTrees(int n)
    {
        return dfs(n);
    }

private:
    int dfs(int n)
    {
        if (n <= 1)
        {
            return 1;
        }

        if (const auto it = mem.find(n); it != std::end(mem))
        {
            return it->second;
        }

        auto total = 0;

        for (auto left = 0; left < n; left++)
        {
            auto right = n - left - 1;

            total += dfs(left) * dfs(right);
        }

        mem[n] = total;

        return total;
    }

private:
    std::unordered_map<int, int> mem;
};