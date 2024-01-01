// https://leetcode.com/problems/high-access-employees/description/

class Solution
{
public:
    std::vector<std::string> findHighAccessEmployees(std::vector<std::vector<std::string>>& access_times)
    {
        std::map<std::string, std::vector<int>> emp;

        for (const auto& at : access_times)
        {
            const auto ts = std::stoi(at[1].substr(0, 2)) * 60 + std::stoi(at[1].substr(2));
            emp[at[0]].push_back(ts);
        }

        std::vector<std::string> res;
        res.reserve(std::size(access_times));

        for (auto& e : emp)
        {
            if (std::size(e.second) < 3)
            {
                continue;
            }

            std::sort(std::begin(e.second), std::end(e.second));

            for (auto i = 2; i < std::size(e.second); i++)
            {
                if (e.second[i] - e.second[i - 2] < 60)
                {
                    res.push_back(e.first);
                    break;
                }
            }
        }

        return res;
    }
};