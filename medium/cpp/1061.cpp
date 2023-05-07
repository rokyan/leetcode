// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/

class Solution
{
public:
    std::string smallestEquivalentString(std::string s1, std::string s2, std::string baseStr)
    {
        std::vector<std::vector<char>> graph(26, std::vector<char>(26));

        for (auto c = 0; c < 26; c++)
        {
            graph[c][c] = true;
        }

        const auto n = std::size(s1);

        for (auto i = 0; i < n; i++)
        {
            graph[s1[i] - 'a'][s2[i] - 'a'] = graph[s2[i] - 'a'][s1[i] - 'a'] = true;
        }

        std::vector<char> eq(26, -1);

        for (auto c = 0; c < 26; c++)
        {
            if (eq[c] == -1)
            {
                std::queue<char> q;
                q.push(c);

                eq[c] = c;

                while (!q.empty())
                {
                    const auto cur = q.front();
                    q.pop();                    

                    for (auto to = 0; to < 26; to++)
                    {
                        if (graph[cur][to] && eq[to] == -1)
                        {
                            q.push(to);
                            eq[cur] = c;
                        }
                    }
                }
            }
        }

        for (auto& c : baseStr)
        {
            c = eq[c - 'a'] + 'a';
        }

        return baseStr;
    }
};