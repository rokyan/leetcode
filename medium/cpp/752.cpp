// https://leetcode.com/problems/open-the-lock/description/

class Solution
{
public:
    int openLock(const std::vector<std::string>& deadends, const std::string& target)
    {
        std::unordered_set<std::string> forbidden(
            std::cbegin(deadends), std::cend(deadends));

        if (forbidden.count("0000") || forbidden.count(target))
        {
            return -1;
        }

        std::queue<std::string> q;
        q.push("0000");

        std::unordered_map<std::string, int> dist{{"0000", 0}};

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            if (cur == target)
            {
                return dist[cur];
            }

            const auto d = dist[cur];

            for (auto i = 0; i < 4; i++)
            {
                auto orig = cur[i];

                cur[i] = (orig - '0' + 1) % 10 + '0';

                if (forbidden.count(cur) == 0 && dist.count(cur) == 0)
                {
                    dist[cur] = d + 1;
                    q.push(cur);
                }

                cur[i] = (orig - '0' - 1 + 10) % 10 + '0';

                if (forbidden.count(cur) == 0 && dist.count(cur) == 0)
                {
                    dist[cur] = d + 1;
                    q.push(cur);
                }

                cur[i] = orig;
            }
        }

        return -1;
    }
};