// https://leetcode.com/problems/minimum-number-of-people-to-teach/description/

class Solution
{
public:
    int minimumTeachings(int n, const std::vector<std::vector<int>>& languages, const std::vector<std::vector<int>>& friendships)
    {
        const auto m = std::size(languages);

        std::vector<std::vector<char>> good(m, std::vector<char>(m));

        for (const auto& e : friendships)
        {
            const auto u = e[0] - 1;
            const auto v = e[1] - 1;

            auto hasCommon = false;

            std::unordered_set<int> s(std::cbegin(languages[u]), std::cend(languages[u]));

            for (auto lang : languages[v])
            {
                if (s.count(lang) > 0)
                {
                    hasCommon = true;
                    break;
                }
            }

            good[u][v] = hasCommon;
        }

        std::vector<int> cnt(n);

        for (auto l = 0; l < n; l++)
        {
            std::vector<char> taken(m);

            for (const auto& e : friendships)
            {
                const auto u = e[0] - 1;
                const auto v = e[1] - 1;

                if (!good[u][v])
                {
                    cnt[l] += !taken[u] && std::find(std::cbegin(languages[u]), std::cend(languages[u]), l + 1) == std::cend(languages[u]);
                    cnt[l] += !taken[v] && std::find(std::cbegin(languages[v]), std::cend(languages[v]), l + 1) == std::cend(languages[v]);
                    taken[u] = taken[v] = true;
                }
            }           
        }

        return *std::min_element(std::cbegin(cnt), std::cend(cnt));
    }
};