// https://leetcode.com/problems/design-a-todo-list/description/

class TodoList
{
private:
    struct Task
    {
        Task(
            int id,
            const std::string& description,
            int dueDate,
            const std::vector<std::string>& tags,
            bool complete = false)
            : id{id}
            , description{description}
            , dueDate{dueDate}
            , tags{tags}
            , complete{complete}
        {}

        int id;
        std::string description;
        int dueDate;
        std::vector<std::string> tags;
        bool complete;

        bool operator<(const Task& other) const
        {
            return dueDate < other.dueDate || dueDate == other.dueDate && id < other.id;
        }
    };

public:
    TodoList() {}
    
    int addTask(int userId, const std::string& taskDescription, int dueDate, const std::vector<std::string>& tags)
    {
        const auto taskId = id++;
        userTasks[userId].emplace(taskId, taskDescription, dueDate, tags);
        return taskId;
    }
    
    std::vector<std::string> getAllTasks(int userId)
    {
        std::vector<std::string> res;

        if (const auto it = userTasks.find(userId); it != std::end(userTasks))
        {
            const auto& tasks = it->second;

            for (const auto& task : tasks)
            {
                if (!task.complete)
                {
                    res.push_back(task.description);
                }
            }
        }

        return res;
    }
    
    std::vector<std::string> getTasksForTag(int userId, const std::string& tag)
    {
        std::vector<std::string> res;

        if (const auto it = userTasks.find(userId); it != std::end(userTasks))
        {
            const auto& tasks = it->second;           

            for (const auto& task : tasks)
            {
                if (!task.complete &&
                    std::find_if(std::cbegin(task.tags), std::cend(task.tags),
                    [&tag](const auto& t) { return t == tag; }) != std::end(task.tags))
                {
                    res.push_back(task.description);
                }
            }
        }

        return res;       
    }
    
    void completeTask(int userId, int taskId)
    {
        if (auto it = userTasks.find(userId); it != std::end(userTasks))
        {
            auto& tasks = it->second;
            auto taskIt = std::begin(tasks);

            while (taskIt != std::end(tasks))
            {
                if (!taskIt->complete && taskIt->id == taskId)
                {
                    auto toModify = *taskIt;
                    toModify.complete = true;
                    tasks.erase(taskIt);
                    tasks.insert(toModify);
                    return;
                }

                ++taskIt;
            }
        }        
    }

private:
    int id = 1;
    std::unordered_map<int, std::set<Task>> userTasks;
};

/**
 * Your TodoList object will be instantiated and called as such:
 * TodoList* obj = new TodoList();
 * int param_1 = obj->addTask(userId,taskDescription,dueDate,tags);
 * vector<string> param_2 = obj->getAllTasks(userId);
 * vector<string> param_3 = obj->getTasksForTag(userId,tag);
 * obj->completeTask(userId,taskId);
 */