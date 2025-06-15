// https://leetcode.com/problems/maximize-profit-from-task-assignment/description/

class Solution
{
public:
    long long maxProfit(const std::vector<int>& workers, const std::vector<std::vector<int>>& tasks)
    {
        std::unordered_map<int, std::vector<int>> tasksPerSkill;

        for (const auto& task : tasks)
        {
            if (const auto it = tasksPerSkill.find(task[0]); it != std::end(tasksPerSkill))
            {
                it->second.push_back(task[1]);
            }
            else
            {
                tasksPerSkill[task[0]].push_back(task[1]);
            }
        }

        for (auto& [_, taskList] : tasksPerSkill)
        {
            std::ranges::sort(taskList);
        }

        auto res = 0LL;

        for (const auto worker : workers)
        {
            if (const auto it = tasksPerSkill.find(worker);
                it != std::end(tasksPerSkill) && std::size(it->second) > 0)
            {
                res += it->second.back();
                it->second.pop_back();
            }
        }

        auto maxProfit = 0;

        for (const auto& [_, taskList] : tasksPerSkill)
        {
            if (taskList.empty())
            {
                continue;
            }

            maxProfit = std::max(maxProfit,
                *std::max_element(std::cbegin(taskList), std::cend(taskList)));
        }

        res += maxProfit;

        return res;
    }
};