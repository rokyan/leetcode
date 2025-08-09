// https://leetcode.com/problems/implement-router/description/

class Router
{
private:
    struct Packet
    {
    public:
        Packet(int source, int destination, int timestamp, int assignedTimestamp)
            : source{source}
            , destination{destination}
            , timestamp{timestamp}
            , assignedTimestamp{assignedTimestamp}
        {}

        std::string encode() const
        {
            return std::to_string(source)
                + "#" + std::to_string(destination)
                + "#" + std::to_string(timestamp);
        }

        int source;
        int destination;
        int timestamp;
        int assignedTimestamp;
    };

public:
    Router(int memoryLimit)
        : total{0}
        , curts{0}
        , memoryLimit{memoryLimit}
    {        
    }
    
    bool addPacket(int source, int destination, int timestamp)
    {
        const auto packet = Packet{source, destination, timestamp, ++curts};
        const auto encoded = packet.encode();

        if (probe.insert(encoded).second)
        {
            packets[destination].push_back(packet);
            bestDestination.insert({curts, destination});

            if (total++ == memoryLimit)
            {
                const auto dest = std::cbegin(bestDestination)->second;

                bestDestination.erase(std::cbegin(bestDestination));
                const auto poppedPacket = packets[dest].front();
                packets[dest].pop_front();
                probe.erase(poppedPacket.encode());

                if (!packets[dest].empty())
                {
                    bestDestination.insert({packets[dest].front().assignedTimestamp, dest});
                }

                total--;
            }

            return true;
        }

        return false;
    }
    
    std::vector<int> forwardPacket()
    {
        if (total == 0)
        {
            return {};
        }

        const auto dest = std::cbegin(bestDestination)->second;

        bestDestination.erase(std::cbegin(bestDestination));
        const auto poppedPacket = packets[dest].front();
        packets[dest].pop_front();
        probe.erase(poppedPacket.encode());

        total--;

        return {poppedPacket.source, poppedPacket.destination, poppedPacket.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime)
    {
        if (packets[destination].empty())
        {
            return 0;
        }

        const auto& packetsPerDestination = packets[destination];

        auto res = 0;

        const auto first = std::lower_bound(std::cbegin(packetsPerDestination), std::cend(packetsPerDestination), startTime,
            [](const auto& e, int value) {
                return e.timestamp < value;
            });

        const auto last = std::upper_bound(std::cbegin(packetsPerDestination), std::cend(packetsPerDestination), endTime,
            [](int value, const auto& e) {
                return value < e.timestamp;
            });

        return std::distance(first, last);
    }

private:
    int total;
    int curts;
    int memoryLimit;
    std::map<int, int> bestDestination;
    std::unordered_map<int, std::deque<Packet>> packets;
    std::unordered_set<std::string> probe;
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */