// https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/description/

class Solution
{
public:
    std::vector<std::string> alertNames(
        const std::vector<std::string>& keyName,
        const std::vector<std::string>& keyTime)
    {
        std::unordered_map<std::string, std::vector<int>> ts_per_name;

        const int n = std::size(keyName);

        for (int i = 0; i < n; i++)
        {
            const auto& key = keyName[i];
            ts_per_name[key].push_back(to_ts(keyTime[i]));    
        }

        std::vector<std::string> res;
        res.reserve(std::size(ts_per_name));

        for (auto& [name, ts] : ts_per_name)
        {
            if (std::size(ts) >= 3)
            {
                std::ranges::sort(ts);

                for (int i = 2; i < std::size(ts); i++)
                {
                    if (ts[i] - ts[i - 2] <= 60)
                    {
                        res.push_back(name);
                        break;
                    }
                }
            }
        }

        std::ranges::sort(res);
        return res;
    }

private:
    int to_ts(std::string_view time)
    {
        return to_int(time.substr(0, 2)) * 60 + to_int(time.substr(3));
    }

    int to_int(std::string_view s)
    {
        return (s[0] - '0') * 10 + (s[1] - '0');
    }
};