// https://leetcode.com/problems/exclusive-time-of-functions/description/

class Solution
{
public:
    std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs)
    {
        std::vector<std::pair<int, int>> st;
        st.reserve(n);

        std::vector<int> res(n);

        for (const auto& log : logs)
        {
            std::istringstream ss(log);
            std::string token;

            std::getline(ss, token, ':');
            const auto id = std::stoi(token);

            std::getline(ss, token, ':');
            const auto type = token;

            std::getline(ss, token, ':');
            const auto ts = std::stoi(token);

            // std::cout << id << " " << type << " " << ts << std::endl;

            if (type == "start")
            {
                st.emplace_back(id, ts);
            }
            else
            {
                const auto duration = ts - st.back().second + 1;
                res[id] += duration;

                if (st.size() > 1)
                {
                    res[st[st.size() - 2].first] -= duration;
                }

                st.pop_back();
            }
        }

        return res;
    }
};