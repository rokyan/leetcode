// https://leetcode.com/problems/sequentially-ordinal-rank-tracker/description/

class SORTracker
{
public:
    SORTracker()
    {
        p = std::end(locations);
    }
    
    void add(std::string name, int score)
    {
        const auto inserted = locations.emplace(-score, std::move(name)).first;

        if (init && *inserted < *p)
        {
            --p;
        }
    }
    
    std::string get()
    {
        if (!init)
        {
            p = std::begin(locations);
            init = true;
        }

        return (*p++).second;
    }

private:
    set<std::pair<int, std::string>> locations;
    set<std::pair<int, std::string>>::iterator p;
    bool init = false;
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */