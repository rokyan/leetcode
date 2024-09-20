// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

class RandomizedSet
{
public:
    RandomizedSet()
        : gen{ std::random_device{}() }
    {        
    }
    
    bool insert(int val)
    {
        if (val_to_pos.find(val) != std::end(val_to_pos))
        {
            return false;
        }

        vals.push_back(val);
        val_to_pos[val] = std::size(vals) - 1;

        return true;
    }
    
    bool remove(int val)
    {
        if (const auto it = val_to_pos.find(val); it != std::end(val_to_pos))
        {
            const auto pos = it->second;

            val_to_pos[vals.back()] = pos;
            std::swap(vals[pos], vals.back());
            vals.pop_back();

            val_to_pos.erase(val);

            return true;
        }

        return false;
    }
    
    int getRandom()
    {
        return vals[get_index()];
    }

private:
    int get_index()
    {
        std::uniform_int_distribution<> distrib(0, static_cast<int>(std::size(vals)) - 1);
        return distrib(gen);
    }

private:
    std::mt19937 gen;
    std::unordered_map<int, int> val_to_pos;
    std::vector<int> vals;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */