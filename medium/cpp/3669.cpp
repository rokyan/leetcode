// https://leetcode.com/problems/balanced-k-factor-decomposition/description/

class Solution
{
public:
    std::vector<int> minDifference(int n, int k)
    {
        std::vector<int> pd;

        for (auto i = 2; i * i <= n; i++)
        {
            while (n % i == 0)
            {
                pd.push_back(i);
                n /= i;
            }
        }

        if (n > 1)
        {
            pd.push_back(n);
        }

        while (std::size(pd) < k)
        {
            pd.push_back(1);
        }

        std::vector<int> cur;
        dfs(pd, 0, k, cur);
        return res;
    }

private:
    void dfs(const std::vector<int>& pd, std::size_t pos,
        int k, std::vector<int> cur)
    {
        std::ranges::sort(cur);

        if (!mem.insert(cur).second)
        {
            return;
        }

        if (pos == std::size(pd))
        {
            if (std::size(cur) == k)
            {
                auto minVal = cur[0];
                auto maxVal = cur[0];

                for (auto i = 1; i < k; i++)
                {
                    minVal = std::min(minVal, cur[i]);
                    maxVal = std::max(maxVal, cur[i]);
                }

                if (diff == -1 || diff > maxVal - minVal)
                {
                    diff = maxVal - minVal;
                    res = cur;
                }
            } 
        }
        else
        {
            if (std::size(cur) < k)
            {
                cur.push_back(pd[pos]);
                dfs(pd, pos + 1, k, cur);
                cur.pop_back();
            }

            for (auto idx = 0; idx < std::size(cur); idx++)
            {
                cur[idx] *= pd[pos];            
                dfs(pd, pos + 1, k, cur);
                cur[idx] /= pd[pos];
            }
        }
    }

private:
    std::set<std::vector<int>> mem;
    int diff = -1;
    std::vector<int> res;
};