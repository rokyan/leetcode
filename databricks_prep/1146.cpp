class SnapshotArray
{
public:
    SnapshotArray(int length) {}
    
    void set(int index, int val)
    {
        auto& values = data[index];

        if (!values.empty())
        {
            if (values.back().first == snapId)
            {
                values.back().second = val;
            }
            else
            {
                values.emplace_back(snapId, val);
            }
        }
        else
        {
            values.emplace_back(snapId, val);
        }
    }
    
    int snap() noexcept
    {
        return snapId++;
    }
    
    int get(int index, int snapId)
    {
        const auto it = data.find(index);
    
        if (it == std::cend(data))
        {
            return 0;
        }

        const auto& values = it->second;

        auto pos = std::upper_bound(
            std::cbegin(values), std::cend(values),
            std::make_pair(snapId, 1'000'000'001));

        return pos == std::cbegin(values) ? 0 : std::prev(pos)->second;
    }

private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> data;
    int snapId = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */