// https://leetcode.com/problems/sender-with-largest-word-count/description/

class Solution
{
public:
    std::string largestWordCount(std::vector<std::string>& messages, std::vector<std::string>& senders)
    {
        std::unordered_map<std::string, int> cnt;

        for (auto i = 0; i < std::size(messages); i++)
        {
            cnt[senders[i]] += std::count(std::begin(messages[i]), std::end(messages[i]), ' ') + 1;
        }

        return std::max_element(std::begin(cnt), std::end(cnt), [](const auto& left, const auto& right) {
            return left.second < right.second || left.second == right.second && left.first < right.first;
        })->first;
    }
};