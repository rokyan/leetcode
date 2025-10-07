class Logger
{
public:
    Logger() = default;
    
    bool shouldPrintMessage(int timestamp, const std::string& message)
    {
        if (const auto it = messagesWithTs.find(message); it != std::cend(messagesWithTs))
        {
            if (timestamp - it->second >= 10)
            {
                it->second = timestamp;
                return true;
            }
        }
        else
        {
            messagesWithTs.emplace(message, timestamp);
            return true;
        }

        return false;
    }

private:
    std::unordered_map<std::string, int> messagesWithTs;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */