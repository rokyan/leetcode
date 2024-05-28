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

        auto total = 0;

        for (auto left = 0; left < n; left++)
        {
            auto right = n - left - 1;

            total += dfs(left) * dfs(right);
        }

        return total;
    }
};