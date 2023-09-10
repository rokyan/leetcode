// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/

class Solution
{
public:
    int minimumRounds(std::vector<int>& tasks)
    {
        std::unordered_map<int, int> cnt;

        for (auto task : tasks)
        {
            cnt[task]++;
        }

        auto res = 0;

        for (const auto& entry : cnt)
        {
            const auto val = entry.second;

            if (val == 1)
            {
                res = -1;
                break;
            }

            if (val % 3 == 0)
            {
                res += val / 3;
            }
            else if (val % 3 == 1)
            {
                res += 2 + (val - 4) / 3;
            }
            else
            {
                res += 1 + val / 3;
            }
        }

        return res;
    }
};