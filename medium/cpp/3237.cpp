// https://leetcode.com/problems/alt-and-tab-simulation/description/

class Solution
{
public:
    std::vector<int> simulationResult(std::vector<int>& windows, std::vector<int>& queries)
    {
        std::unordered_map<int, int> score;

        auto s = std::size(windows) - 1;

        for (auto i = 0; i < std::size(windows); i++)
        {
            score[windows[i]] = s - i;
        }

        for (auto q : queries)
        {
            score[q] = ++s;
        }

        std::vector<std::pair<int, int>> p;
        p.reserve(std::size(score));

        for (const auto& entry : score)
        {
            p.emplace_back(entry.second, entry.first);
        }

        std::sort(std::begin(p), std::end(p), std::greater<>{});

        std::vector<int> res;
        res.reserve(std::size(score));

        std::transform(std::cbegin(p), std::cend(p), std::back_inserter(res), [](const auto& e) {
            return e.second;
        });

        return res;
    }
};