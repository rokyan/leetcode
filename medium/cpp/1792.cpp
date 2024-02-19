// https://leetcode.com/problems/maximum-average-pass-ratio/

class Solution
{
public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents)
    {
        const auto comp = [](const auto& lhs, const auto& rhs)
        {
            const auto lscore = static_cast<double>(lhs.first + 1) / (lhs.second + 1) -
                static_cast<double>(lhs.first) / lhs.second;
            const auto rscore = static_cast<double>(rhs.first + 1) / (rhs.second + 1) -
                static_cast<double>(rhs.first) / rhs.second;
            return lscore > rscore;
        };

        std::multiset<std::pair<int, int>, decltype(comp)> ms;

        for (const auto& c : classes)
        {
            ms.emplace(c[0], c[1]);
        }

        while (extraStudents--)
        {
            auto picked = *std::cbegin(ms);
            ms.erase(std::cbegin(ms));
            picked.first++;
            picked.second++;
            ms.insert(picked);
        }

        auto tot = .0;

        for (const auto& e : ms)
        {
            tot += static_cast<double>(e.first) / e.second;
        }

        tot /= std::size(ms);

        return tot;
    }
};