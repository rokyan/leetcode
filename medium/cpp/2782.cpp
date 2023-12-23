// https://leetcode.com/problems/number-of-unique-categories/description/

/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution
{
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler)
    {
        std::vector<std::vector<int>> g(n, std::vector<int>());

        for (auto i = 0; i < n; i++)
        {
            for (auto c = 0; c < n; c++)
            {
                if (categoryHandler->haveSameCategory(i, c))
                {
                    g[i].push_back(c);
                }
            }
        }

        auto res = 0;

        std::vector<char> vis(n, false);

        for (auto v = 0; v < n; v++)
        {
            if (!vis[v])
            {
                res++;

                std::queue<int> q;
                q.push(v);
                vis[v] = true;

                while (!q.empty())
                {
                    const auto u = q.front();
                    q.pop();

                    for (auto to : g[u])
                    {
                        if (!vis[to])
                        {
                            vis[to] = true;
                            q.push(to);
                        }
                    }
                }
            }
        }

        return res;
    }
};