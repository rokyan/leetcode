// https://leetcode.com/problems/sort-features-by-popularity/description/

class Solution
{
public:
    std::vector<std::string> sortFeatures(std::vector<std::string>& features, std::vector<std::string>& responses)
    {
        std::unordered_map<std::string, std::pair<int, int>> m;

        for (auto i = 0; i < std::size(features); i++)
        {
            m[features[i]] = { 0, i };
        }

        for (const auto& response : responses)
        {
            std::unordered_set<std::string> seen;

            std::string token;

            for (auto c : response)
            {
                if (c != ' ')
                {
                    token.push_back(c);
                }
                else
                {
                    if (seen.insert(token).second)
                    {
                        if (const auto it = m.find(token); it != std::end(m))
                        {
                            it->second.first++;
                        }
                    }

                    token.clear();
                }
            }

            if (seen.insert(token).second)
            {
                if (const auto it = m.find(token); it != std::end(m))
                {
                    it->second.first++;
                }
            }
        }

        std::vector<std::pair<std::string, std::pair<int, int>>> v(std::cbegin(m), std::cend(m));

        std::sort(std::begin(v), std::end(v), [](const auto& lhs, const auto& rhs) {
            return lhs.second.first > rhs.second.first || lhs.second.first == rhs.second.first && lhs.second.second < rhs.second.second;
        });

        std::vector<std::string> res;
        res.reserve(std::size(v));

        std::transform(std::cbegin(v), std::cend(v), std::back_inserter(res), [](const auto& e) { return e.first; });

        return res;
    }
};