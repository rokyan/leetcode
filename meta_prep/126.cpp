class Solution
{
public:
    std::vector<std::vector<std::string>> findLadders(const std::string& beginWord, const std::string& endWord,
        const std::vector<std::string>& wordList)
    {
        const auto endPos = getPos(endWord, wordList);

        if (endPos == -1)
        {
            return {};
        }

        const auto n = std::size(wordList);

        std::vector<std::vector<int>> graph(n);

        for (auto i = 0; i + 1 < n; i++)
        {
            for (auto j = i + 1; j < n; j++)
            {
                if (i != j && areMatching(wordList[i], wordList[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        std::vector<int> dist(n, 2 * n);
        std::queue<int> q;

        for (auto i = 0; i < n; i++)
        {
            if (areMatching(beginWord, wordList[i]))
            {
                q.push(i);
                dist[i] = 0;
            }
        }

        while (!q.empty())
        {
            const auto v = q.front();
            q.pop();

            for (auto to : graph[v])
            {
                if (dist[to] == 2 * n)
                {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        if (dist[endPos] == 2 * n)
        {
            return {};
        }

        std::vector<std::string> cur;
        std::vector<std::vector<std::string>> res;

        getPaths(endPos, dist, graph, wordList, cur, res, beginWord);

        return res;
    }

private:
    int getPos(const std::string& word, const std::vector<std::string>& wordList)
    {
        const auto pos = std::find(std::cbegin(wordList), std::cend(wordList), word);
        return pos == std::end(wordList)
            ? -1
            : std::distance(std::cbegin(wordList), pos);
    }

    bool areMatching(const std::string& word1, const std::string& word2)
    {
        const auto n = std::size(word1);

        if (std::size(word2) != n)
        {
            return false;
        }

        auto cnt = 0;

        for (auto i = 0; i < n && cnt < 2; i++)
        {
            cnt += word1[i] != word2[i];
        }

        return cnt == 1;
    }

    void getPaths(
        int v,
        const std::vector<int>& dist,
        const std::vector<std::vector<int>>& graph,
        const std::vector<std::string>& wordList,
        std::vector<std::string>& cur,
        std::vector<std::vector<std::string>>& res,
        const std::string& beginWord)
    {
        if (dist[v] == 0)
        {
            cur.push_back(wordList[v]);
            cur.push_back(beginWord);
            res.push_back(cur);
            std::reverse(std::begin(res.back()), std::end(res.back()));
            cur.pop_back();
            cur.pop_back();
        }
        else
        {
            cur.push_back(wordList[v]);

            for (auto to : graph[v])
            {
                if (dist[to] + 1 == dist[v])
                {
                    getPaths(to, dist, graph, wordList, cur, res, beginWord);
                }
            }

            cur.pop_back();
        }
    }
};