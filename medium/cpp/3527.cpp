// https://leetcode.com/problems/find-the-most-common-response/description/

class Solution
{
public:
    std::string findCommonResponse(const std::vector<std::vector<std::string>>& responses)
    {
        std::unordered_map<std::string, int> freq;

        for (const auto& dailyResponses : responses)
        {
            std::unordered_set<std::string> un{
                std::cbegin(dailyResponses),
                std::cend(dailyResponses)};

            for (const auto& r : un)
            {
                freq[r]++;
            }
        }

        std::string res;
        auto times = 0;

        for (const auto& [r, t] : freq)
        {
            if (t > times || t == times && r < res)
            {
                res = r;
                times = t;
            }
        }

        return res;
    }
};