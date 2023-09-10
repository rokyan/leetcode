// https://leetcode.com/problems/snapshot-array/description/

class SnapshotArray
{
public:
    SnapshotArray(int length)
    {     
    }
    
    void set(int index, int val)
    {
        if (const auto it = data.find(index); it != std::end(data))
        {
            if (it->second.back().first == snap_id)
            {
                it->second.back().second = val;
            }
            else
            {
                it->second.emplace_back(snap_id, val);
            }
        }
        else
        {
            data[index].emplace_back(-1, 0);
            data[index].emplace_back(snap_id, val);
        }
    }
    
    int snap()
    {
        return snap_id++;
    }
    
    int get(int index, int snap_id)
    {
        if (const auto it = data.find(index); it != std::end(data))
        {
            auto p = std::upper_bound(std::begin(it->second), std::end(it->second),
                std::make_pair(snap_id, -1));

            return (p != std::end(it->second) && p->first == snap_id) ? p->second : (--p)->second;
        }
        else
        {
            return 0;
        }
    }

private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> data;
    int snap_id = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */