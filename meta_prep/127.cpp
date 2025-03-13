class Solution
{
public:
    int ladderLength(const std::string& beginWord, const std::string& endWord,
        const std::vector<std::string>& wordList)
    {
        const auto endIt = std::find(std::cbegin(wordList), std::cend(wordList), endWord);

        if (endIt == std::cend(wordList))
        {
            return 0;
        }

        const auto endPos = std::distance(std::cbegin(wordList), endIt);

        const auto n = std::size(wordList);

        std::vector<std::vector<int>> graph(n + 1);

        for (auto i = 0; i < n; i++)
        {
            if (areMatching(beginWord, wordList[i]))
            {
                graph[n].push_back(i);
            }
        }

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                if (j != i && areMatching(wordList[i], wordList[j]))
                {
                    graph[i].push_back(j);
                }
            }
        }

        std::queue<int> q;
        q.push(n);

        const auto inf = n * n;

        std::vector<int> distance(n + 1, inf);
        distance[n] = 0;

        while (!q.empty())
        {
            const auto v = q.front();
            q.pop();

            if (v == endPos)
            {
                return distance[v] + 1;
            }

            for (auto to : graph[v])
            {
                if (distance[to] == inf)
                {
                    distance[to] = distance[v] + 1;
                    q.push(to);
                }
            }
        }

        return 0;
    }

private:
    bool areMatching(const std::string& x, const std::string& y)
    {
        auto dcount = 0;

        for (auto i = 0; i < std::size(x) && dcount < 2; i++)
        {
            if (x[i] != y[i])
            {
                dcount++;
            }
        }

        return dcount == 1;
    }
};