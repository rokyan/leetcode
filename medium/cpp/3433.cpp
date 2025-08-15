// https://leetcode.com/problems/count-mentions-per-user/description/

class Solution
{
public:
    std::vector<int> countMentions(int numberOfUsers, std::vector<std::vector<std::string>>& events)
    {
        std::ranges::sort(events, [](const auto& lhs, const auto& rhs) {
            const auto ts1 = std::stoi(lhs[1]);
            const auto ts2 = std::stoi(rhs[1]);

            return ts1 < ts2 || ts1 == ts2 && lhs[0] == "OFFLINE";
        });

        std::vector<int> res(numberOfUsers);

        std::unordered_map<int, std::pair<bool, int>> state;

        for (auto id = 0; id < numberOfUsers; id++)
        {
            state[id] = {true, -1};
        }

        for (const auto& event : events)
        {
            if (event[0] == "MESSAGE")
            {
                const auto ts = std::stoi(event[1]);
                const auto& mentions = event[2];

                if (mentions == "ALL")
                {
                    for (auto id = 0; id < numberOfUsers; id++)
                    {
                        res[id]++;
                    }
                }
                else if (mentions == "HERE")
                {
                    for (auto& e : state)
                    {
                        if (e.second.first)
                        {
                            res[e.first]++;
                        }
                        else
                        {
                            if (e.second.second <= ts)
                            {
                                e.second.first = true;
                                res[e.first]++;
                            }
                        }
                    }
                }
                else
                {
                    auto id = 0;

                    for (auto i = 0; i < std::size(mentions); )
                    {
                        i += 2;

                        while (i < std::size(mentions) && mentions[i] != ' ')
                        {
                            id = 10 * id + mentions[i] - '0';
                            i++;
                        }

                        if (!state[id].first && state[id].second <= ts)
                        {
                            state[id].first = true;
                            state[id].second = -1;
                        }

                        res[id]++;

                        id = 0;
                        i++;
                    }
                }
            }
            else
            {
                const auto ts = std::stoi(event[1]);
                const auto id = std::stoi(event[2]);
                state[id] = {false, ts + 60};
            }
        }

        return res;    
    }
};