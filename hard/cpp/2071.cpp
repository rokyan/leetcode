// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/

class Solution
{
public:
    int maxTaskAssign(std::vector<int>& tasks, std::vector<int>& workers,
        int pills, int strength)
    {
        std::ranges::sort(tasks);
        std::ranges::sort(workers);

        int lo = 0;
        int hi = std::min(tasks.size(), workers.size());

        while (lo < hi)
        {
            const int mid = lo + (hi - lo + 1) / 2;

            if (check(tasks, workers, pills, strength, mid))
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return lo;
    }

private:
    static bool check(const std::vector<int>& tasks, const std::vector<int>& workers,
        int pills, int strength, int take)
    {
        std::deque<int> dq;

        for (int i = workers.size() - take, p = 0; i < workers.size(); i++)
        {
            const int worker = workers[i];

            while (p < take && tasks[p] <= worker + strength)
            {
                dq.push_back(tasks[p++]);
            }

            if (dq.empty())
            {
                return false;
            }

            if (dq.front() <= worker)
            {
                dq.pop_front();
            }
            else if (pills > 0)
            {
                dq.pop_back();
                pills--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};