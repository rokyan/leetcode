class Solution
{
public:
    std::vector<int> exclusiveTime(int n, const std::vector<std::string>& logs)
    {
        std::vector<int> times(n);

        std::vector<std::pair<int, int>> st;
        st.reserve(n);

        for (const auto& logline: logs)
        {
            const auto [id, type, timestamp] = parse(logline);

            if (type == "start")
            {
                st.emplace_back(id, timestamp);
            }
            else
            {
                const auto duration = timestamp - st.back().second + 1;
                times[id] += duration;

                st.pop_back();

                if (!st.empty())
                {
                    times[st.back().first] -= duration;
                }
            }
        }

        return times;
    }

private:
    std::tuple<int, std::string, int> parse(const std::string& logline)
    {
        std::stringstream ss{logline};
        std::string token;

        const auto next = [&ss, &token] {
            std::getline(ss, token, ':');
            return token;
        };

        const auto id = std::stoi(next());
        const auto type = next();
        const auto timestamp = std::stoi(next());

        return std::make_tuple(id, type, timestamp);
    }
};