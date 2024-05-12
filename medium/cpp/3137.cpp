// https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/description/

class Solution
{
public:
    int minimumOperationsToMakeKPeriodic(std::string word, int k)
    {
        const auto n = std::size(word);

        std::unordered_map<std::string_view, int> cnt;

        const std::string_view view{ std::cbegin(word), std::cend(word) };
        auto max_freq = 0;

        for (auto i = 0; i < n; i += k)
        {
            max_freq = std::max(max_freq, ++cnt[view.substr(i, k)]);
        }

        return n / k - max_freq;
    }
};