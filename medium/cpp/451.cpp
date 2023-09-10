// https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution
{
public:
    std::string frequencySort(std::string s)
    {
        std::unordered_map<char, int> freq;

        for (auto c : s)
        {
            freq[c]++;
        }

        std::vector<std::pair<int, char>> cnt;

        for (auto&& entry : freq)
        {
            cnt.emplace_back(entry.second, entry.first);
        }

        std::sort(std::begin(cnt), std::end(cnt), std::greater<>{});

        const auto n = std::size(s);

        std::string res;
        res.resize(n);

        auto last = 0;

        for (auto&& entry : cnt)
        {
            for (auto times = 0; times < entry.first; times++)
            {
                res[last++] = entry.second;
            }
        }

        return res;
    }
};