// https://leetcode.com/problems/report-spam-message/description/

class Solution
{
public:
    bool reportSpam(const std::vector<std::string>& message, const std::vector<std::string>& bannedWords)
    {
        auto cnt = 0;

        std::unordered_set<std::string> probe(std::cbegin(bannedWords), std::cend(bannedWords));

        for (const auto& m : message)
        {
            if (const auto it = probe.find(m); it != std::end(probe))
            {
                cnt++;
            }

            if (cnt == 2)
            {
                return true;
            }
        }

        return false;
    }
};