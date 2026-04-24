// https://leetcode.com/problems/design-event-manager/description/

class EventManager
{
private:
    struct comp
    {
        bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const
        {
            return lhs.second > rhs.second || lhs.second == rhs.second && lhs.first < rhs.first;
        }
    };

public:
    EventManager(const std::vector<std::vector<int>>& events)
    {
        for (const auto& event : events)
        {
            prio.emplace(event[0], event[1]);
            ordered.emplace(event[0], event[1]);
        }
    }
    
    void updatePriority(int eventId, int newPriority)
    {
        ordered.erase({eventId, prio[eventId]});
        prio[eventId] = newPriority;
        ordered.emplace(eventId, prio[eventId]);
    }
    
    int pollHighest()
    {
        if (ordered.empty())
        {
            return -1;
        }

        const int id = ordered.begin()->first;
        prio.erase(id);
        ordered.erase(ordered.begin());
        return id;
    }

private:
    std::unordered_map<int, int> prio;
    std::set<std::pair<int, int>, comp> ordered;
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */