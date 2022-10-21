// https://leetcode.com/problems/design-underground-system/

class UndergroundSystem
{
public:
    UndergroundSystem()
    {
        
    }
    
    void checkIn(int id, std::string stationName, int t)
    {
        checkins[id] = { stationName, t };
    }
    
    void checkOut(int id, std::string stationName, int t)
    {
        auto it = checkins.find(id);
        
        auto stations = it->second.first + "#" + stationName;
        
        auto mappings_it = mappings.find(stations);
        
        if (mappings_it == std::end(mappings))
        {
            mappings[stations] = { t - it->second.second, 1 };
        }
        else
        {
            mappings_it->second.first += t - it->second.second;
            mappings_it->second.second++;
        }
    }
    
    double getAverageTime(std::string startStation, std::string endStation)
    {
        auto it = mappings.find(startStation + "#" + endStation);
        
        return 1.0 * it->second.first / it->second.second;
    }
    
private:
    std::unordered_map<int, std::pair<std::string, int>> checkins;
    std::unordered_map<std::string, std::pair<int, int>> mappings;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */