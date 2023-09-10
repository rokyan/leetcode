// https://leetcode.com/problems/task-scheduler-ii/description/

class Solution
{
public:
    long long taskSchedulerII(std::vector<int>& tasks, int space)
    {
        std::unordered_map<int, long long> last;
        auto time = 0LL;

        for (const auto task : tasks)
        {
            time++;

            const auto it = last.find(task);

            if (it != std::end(last))
            {
                if (time - it->second <= space + 1)
                {
                    time = it->second + space + 1;
                }
            }

            last[task] = time;
        }

        return time;
    }
};