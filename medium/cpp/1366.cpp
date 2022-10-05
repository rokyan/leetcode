// https://leetcode.com/problems/rank-teams-by-votes/

class Solution
{
public:
    std::string rankTeams(std::vector<std::string>& votes)
    {
        std::vector<std::pair<char, std::vector<int>>> v(26);
        
        for (int pos = 0; pos < 26; pos++)
        {
            v[pos] = { pos, std::vector<int>(26) };
        }
        
        for (const auto& vote : votes)
        {
            for (int pos = 0; pos < std::size(vote); pos++)
            {
                v[vote[pos] - 'A'].second[pos]++;
            }
        }
        
        std::sort(std::begin(v), std::end(v), [](const auto& left, const auto& right) {
            return left.second > right.second || left.second == right.second && left.first < right.first;
        });
        
        std::string ans;
        
        for (int pos = 0; pos < 26; pos++)
        {
            if (std::none_of(std::begin(v[pos].second), std::end(v[pos].second), [](auto c) {
                return c > 0;
            }))
            {
                break;
            }
            
            ans.push_back(v[pos].first + 'A');
        }
        
        return ans;
    }
};