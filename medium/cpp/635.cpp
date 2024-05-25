// https://leetcode.com/problems/design-log-storage-system/description/

class LogSystem
{
private:
    static std::unordered_map<std::string, int> offsets;

public:
    LogSystem()
    {        
    }
    
    void put(int id, const std::string& timestamp)
    {
        dates_with_ids.emplace(timestamp, id);
    }
    
    std::vector<int> retrieve(const std::string& start, const std::string& end, const std::string& granularity)
    {
        const auto offset = offsets[granularity];
        const auto tstart = truncate(start, offset);

        auto it = dates_with_ids.lower_bound(tstart);

        std::vector<int> ids;

        while (it != std::end(dates_with_ids) && it->first.substr(0, offset) <= end.substr(0, offset))
        {
            ids.push_back(it->second);
            ++it;
        }

        return ids;
    }

private:
    std::string truncate(const std::string& date, int offset)
    {
        auto truncated = date;

        for (auto pos = offset; pos < std::size(truncated); pos++)
        {
            if (truncated[pos] != ':')
            {
                truncated[pos] = '0';
            }
        }

        return truncated;
    }

private:
    std::map<std::string, int> dates_with_ids;
};

std::unordered_map<std::string, int> LogSystem::offsets =
{
    { "Year", 4 },
    { "Month", 7 },
    { "Day", 10 },
    { "Hour", 13 },
    { "Minute", 16 },
    { "Second", 19 }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */