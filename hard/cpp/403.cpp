// https://leetcode.com/problems/frog-jump/description/

class Solution
{
public:
    bool canCross(const std::vector<int>& stones)
    {
        const auto n = std::size(stones);

        std::set<std::pair<int, int>> pos;

        std::unordered_set<int> exists(std::cbegin(stones), std::cend(stones));

        std::queue<std::pair<int, int>> q;

        if (exists.find(stones[0] + 1) != std::end(exists))
        {
            q.push({stones[0] + 1, 1});
            pos.insert({stones[0] + 1, 1});
        }
        else
        {
            return false;
        }

        while (!q.empty())
        {
            const auto [p, k] = q.front();
            q.pop();

            if (p == stones.back())
            {
                return true;
            }

            for (auto i = k - 1; i <= k + 1; i++)
            {
                if (exists.count(p + i) == 0)
                {
                    continue;
                }

                if (pos.insert({p + i, i}).second)
                {
                    q.push({p + i, i});
                }
            }
        }

        return false;
    }
};