// https://leetcode.com/problems/design-task-manager/description/

class TaskManager
{
public:
    TaskManager(const std::vector<std::vector<int>>& tasks)
    {
        for (const auto& t : tasks)
        {
            add(t[0], t[1], t[2]);
        }
    }
    
    void add(int userId, int taskId, int priority)
    {
        tasks.emplace(taskId, std::make_pair(userId, priority));
        ordered.emplace(priority, taskId);
    }
    
    void edit(int taskId, int newPriority)
    {
        ordered.erase(std::make_pair(tasks[taskId].second, taskId));
        tasks[taskId].second = newPriority;
        ordered.emplace(newPriority, taskId);
    }
    
    void rmv(int taskId)
    {
        ordered.erase(std::make_pair(tasks[taskId].second, taskId));
        tasks.erase(taskId);
    }
    
    int execTop()
    {
        if (tasks.empty())
        {
            return -1;
        }

        const auto top = *ordered.cbegin();
        ordered.erase(ordered.cbegin());

        const auto topTask = tasks[top.second];
        tasks.erase(top.second);

        return topTask.first;
    }

private:
    std::unordered_map<int, std::pair<int, int>> tasks;
    std::set<std::pair<int, int>, std::greater<>> ordered;
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */