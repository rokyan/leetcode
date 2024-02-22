// https://leetcode.com/problems/single-threaded-cpu/description/

class Solution
{
private:
    struct task
    {
        int en_time;
        int pro_time;
        int index;
    };
public:
    vector<int> getOrder(std::vector<std::vector<int>>& tasks)
    {
        std::vector<task> t;
        t.reserve(std::size(tasks));

        for (auto i = 0; i < std::size(tasks); i++)
        {
            t.emplace_back(tasks[i][0], tasks[i][1], i);
        }

        std::sort(std::begin(t), std::end(t), [](const auto& lhs, const auto& rhs) {
            return lhs.en_time < rhs.en_time;
        });

        std::vector<int> res;
        res.reserve(std::size(t));

        const auto comp = [](const auto& lhs, const auto& rhs)
        {
            return lhs.pro_time < rhs.pro_time || lhs.pro_time == rhs.pro_time && lhs.index < rhs.index;
        };

        auto cur_time = static_cast<long long>(t.front().en_time);
        auto p = 0;
        std::set<task, decltype(comp)> tasks_queue;

        while (p < std::size(t) && t[p].en_time <= cur_time)
        {
            tasks_queue.insert(t[p++]);
        }

        while (!tasks_queue.empty())
        {
            const auto task = *std::cbegin(tasks_queue);
            tasks_queue.erase(std::cbegin(tasks_queue));

            cur_time += task.pro_time;
            res.push_back(task.index);

            while (p < std::size(t) && t[p].en_time <= cur_time)
            {
                tasks_queue.insert(t[p++]);
            }

            if (tasks_queue.empty())
            {
                if (p < std::size(t))
                {
                    cur_time = t[p].en_time;

                    while (p < std::size(t) && t[p].en_time <= cur_time)
                    {
                        tasks_queue.insert(t[p++]);
                    }
                }
            }
        }

        return res;
    }
};