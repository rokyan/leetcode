// https://leetcode.com/problems/process-tasks-using-servers/description/

class Solution
{
public:
    std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks)
    {
        std::set<std::pair<int, int>> free_servers;

        for (auto i = 0; i < std::size(servers); i++)
        {
            free_servers.emplace(servers[i], i);
        }

        std::queue<int> tasks_queue;

        std::vector<int> res(std::size(tasks));

        std::set<std::tuple<int, int, int>> busy_servers;

        for (auto j = 0; j < std::size(tasks); j++)
        {
            tasks_queue.push(j);

            while (!busy_servers.empty() && std::get<0>(*std::cbegin(busy_servers)) <= j)
            {
                free_servers.emplace(std::get<1>(*std::cbegin(busy_servers)), std::get<2>(*std::cbegin(busy_servers)));
                busy_servers.erase(std::cbegin(busy_servers));
            }

            while (!tasks_queue.empty() && !free_servers.empty())
            {
                const auto task_id = tasks_queue.front();
                tasks_queue.pop();
                const auto server_id = std::cbegin(free_servers)->second;
                free_servers.erase(std::cbegin(free_servers));
                res[task_id] = server_id;
                busy_servers.insert({j + tasks[task_id], servers[server_id], server_id });
            }
        }

        while (!tasks_queue.empty())
        {
            auto j = std::get<0>(*std::cbegin(busy_servers));

            while (!busy_servers.empty() && j == std::get<0>(*std::cbegin(busy_servers)))
            {
                const auto server_id = std::get<2>(*std::cbegin(busy_servers));
                free_servers.emplace(servers[server_id], server_id);
                busy_servers.erase(std::cbegin(busy_servers));
            }

            while (!tasks_queue.empty() && !free_servers.empty())
            {
                const auto task_id = tasks_queue.front();
                tasks_queue.pop();
                const auto server_id = std::cbegin(free_servers)->second;
                free_servers.erase(std::cbegin(free_servers));
                res[task_id] = server_id;
                busy_servers.insert({j + tasks[task_id], servers[server_id], server_id });
            }
        }

        return res;
    }
};