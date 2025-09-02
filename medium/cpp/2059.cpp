// https://leetcode.com/problems/minimum-operations-to-convert-number/description/

class Solution
{
public:
    int minimumOperations(const std::vector<int>& nums, int start, int goal)
    {
        const auto n = std::size(nums);

        std::queue<int> q;
        q.push(start);

        std::unordered_map<int, int> dist;
        dist[start] = 0;

        while (!q.empty())
        {
            const auto val = q.front();
            q.pop();

            for (const auto num : nums)
            {
                for (const auto next : {val + num, val - num, val ^ num})
                {
                    if (next == goal)
                    {
                        return dist[val] + 1;
                    }


                    if (dist.count(next) == 0 && next >= 0 && next <= 1000)
                    {
                        dist[next] = dist[val] + 1;
                        q.push(next);
                    }
                }
            }
        }

        return -1;
    }
};