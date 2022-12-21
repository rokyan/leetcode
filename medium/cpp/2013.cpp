// https://leetcode.com/problems/detect-squares/

namespace std
{
    template<>
    class hash<std::vector<int>>
    {
    public:
        std::size_t operator()(const std::vector<int>& v) const
        {
            return std::hash<int>()(v[0]) ^ std::hash<int>()(v[1]);
        }
    };
}

class DetectSquares
{  
public:
    DetectSquares()
    {
    }
    
    void add(std::vector<int> point)
    {
        cnt[point]++;
    }
    
    int count(std::vector<int> point)
    {
        int res = 0;
        
        for (const auto& entry : cnt)
        {
            const auto key = entry.first;
            
            if (key[0] == point[0] || key[1] == point[1])
            {
                continue;
            }
            
            if (std::abs(key[0] - point[0]) != std::abs(key[1] - point[1]))
            {
                continue;
            }
            
            int ways = entry.second;
            
            auto it = cnt.find({ key[0], point[1] });
            
            if (it == std::end(cnt))
            {
                continue;
            }
            else
            {
                ways *= it->second;
            }
            
            it = cnt.find({ point[0], key[1] });
            
            if (it == std::end(cnt))
            {
                continue;
            }
            else
            {
                ways *= it->second;
            }
            
            res += ways;
        }
        
        return res;
    }
        
private:
    std::unordered_map<std::vector<int>, int> cnt;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */