// https://leetcode.com/problems/course-schedule-iii/description/

class Solution
{
public:
    int scheduleCourse(std::vector<std::vector<int>>& courses)
    {
        std::sort(std::begin(courses), std::end(courses), [](const auto& lhs, const auto& rhs) {
            return lhs[1] < rhs[1];
        });

        const auto n = std::size(courses);

        auto last = 0;
        
        std::priority_queue<int> pq;

        for (auto i = 0; i < n; i++)
        {
            last += courses[i][0];
            pq.push(courses[i][0]);

            if (last > courses[i][1])
            {
                auto duration = pq.top();
                pq.pop();
                last -= duration;
            }
        }

        return std::size(pq);
    }
};