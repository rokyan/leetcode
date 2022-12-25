// https://leetcode.com/problems/reorder-data-in-log-files/description/

class Solution
{
public:
    std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs)
    {
        auto mid = std::stable_partition(std::begin(logs), std::end(logs),
            [](const std::string& log) {
               const auto pos = log.find(' ');
                return log[pos + 1] >= 'a';
            });
        
        std::sort(std::begin(logs), mid,
            [](const std::string& lhs, const std::string& rhs) {
                const auto lhs_pos = lhs.find(' ');
                const auto rhs_pos = rhs.find(' ');
                
                return lhs.substr(lhs_pos + 1) < rhs.substr(rhs_pos + 1);
            });
        
        return logs;
    }
};