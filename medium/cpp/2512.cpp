// https://leetcode.com/problems/reward-top-k-students/description/

class Solution
{
public:
    std::vector<int> topStudents(std::vector<std::string>& positive_feedback, std::vector<std::string>& negative_feedback,
        std::vector<std::string>& report, std::vector<int>& student_id, int k)
    {
        std::unordered_set<std::string> positive_probe(std::begin(positive_feedback), std::end(positive_feedback));
        std::unordered_set<std::string> negative_probe(std::begin(negative_feedback), std::end(negative_feedback));

        const auto n = std::size(report);

        std::unordered_map<int, int> cnt;

        for (auto i = 0; i < n; i++)
        {
            const auto& cur_report = report[i];
            const auto cur_id = student_id[i];

            std::istringstream is{ cur_report };
            std::string word;
            auto balance = 0;

            while (is >> word)
            {
                if (positive_probe.count(word) > 0)
                {
                    balance += 3;
                }
                else if (negative_probe.count(word) > 0)
                {
                     balance -= 1;
                }
            }

            cnt[cur_id] += balance;
        }

        std::vector<std::pair<int, int>> data;
        data.reserve(std::size(cnt));

        for (const auto& entry : cnt)
        {
            data.emplace_back(entry.second, entry.first);
        }

        std::partial_sort(std::begin(data), std::begin(data) + k, std::end(data), [](const auto& left, const auto& right) {
            return left.first > right.first || left.first == right.first && left.second < right.second;
        });

        std::vector<int> res(k);

        std::transform(std::begin(data), std::begin(data) + k, std::begin(res), [](const auto& entry) {
            return entry.second;
        });

        return res;
    }
};