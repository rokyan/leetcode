// https://leetcode.com/problems/build-a-matrix-with-conditions/description/

class Solution
{
public:
    std::vector<std::vector<int>> buildMatrix(
        int k,
        std::vector<std::vector<int>>& rowConditions,
        std::vector<std::vector<int>>& colConditions)
    {
        std::vector<std::vector<char>> less(k, std::vector<char>(k));

        for (const auto& cond : rowConditions)
        {
            less[cond[0] - 1][cond[1] - 1] = true;
        }

        std::vector<int> order;
        order.reserve(k);

        std::vector<int> color(k);

        for (auto v = 0; v < k; v++)
        {
            if (color[v] == 0)
            {
                if (dfs(v, k, less, color, order))
                {
                    return {};
                }
            }
        }

        std::ranges::reverse(order);

        std::vector<int> row(k);

        for (auto i = 0; i < k; i++)
        {
            row[order[i]] = i;
        }

        for (auto& r : less)
        {
            std::ranges::fill(r, 0);
        }

        for (const auto& cond : colConditions)
        {
            less[cond[0] - 1][cond[1] - 1] = true;
        }

        std::ranges::fill(color, 0);
        order.clear();

        for (auto v = 0; v < k; v++)
        {
            if (color[v] == 0)
            {
                if (dfs(v, k, less, color, order))
                {
                    return {};
                }
            }
        }

        std::ranges::reverse(order);

        std::vector<std::vector<int>> res(k, std::vector<int>(k));

        for (auto i = 0; i < k; i++)
        {
            res[row[order[i]]][i] = order[i] + 1;
        }   

        return res;
    }

private:
    bool dfs(int v, int k, const std::vector<std::vector<char>>& less,
        std::vector<int>& color, std::vector<int>& order)
    {
        color[v] = 1;
        auto found = false;

        for (auto to = 0; to < k; to++)
        {
            if (less[v][to])
            {
                if (color[to] == 1)
                {
                    return true;
                }

                if (color[to] == 0)
                {
                    found |= dfs(to, k, less, color, order);
                }
            }
        }

        color[v] = 2;
        order.push_back(v);
        return found;
    }
};