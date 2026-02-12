// https://leetcode.com/problems/design-ride-sharing-system/description/

class RideSharingSystem
{
public:
    RideSharingSystem() = default;
    
    void addRider(int riderId)
    {
        riders.push_back(riderId);
        riderPointers.emplace(riderId, --std::end(riders));
    }
    
    void addDriver(int driverId)
    {
        drivers.push_back(driverId);
    }
    
    std::vector<int> matchDriverWithRider()
    {
        if (drivers.empty() || riders.empty())
        {
            return {-1, -1};
        }

        std::vector<int> res(2);

        res[0] = drivers.front();
        drivers.pop_front();
        res[1] = riders.front();
        riders.pop_front();
        riderPointers.erase(res[1]);

        return res;
    }
    
    void cancelRider(int riderId)
    {
        if (const auto it = riderPointers.find(riderId); it != riderPointers.end())
        {
            riders.erase(it->second);
            riderPointers.erase(it);
        }
    }

private:
    std::list<int> drivers;
    std::list<int> riders;
    std::unordered_map<int, std::list<int>::iterator> riderPointers;
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */