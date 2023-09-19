// https://leetcode.com/problems/range-frequency-queries/description/

class RangeFreqQuery
{
public:
    RangeFreqQuery(vector<int>& arr)
    {
        for (auto p = 0; p < std::size(arr); p++)
        {
            vtp[arr[p]].push_back(p);
        }
    }
    
    int query(int left, int right, int value)
    {
        const auto it = vtp.find(value);

        if (it == std::end(vtp))
        {
            return 0;
        }

        const auto& ps = it->second;

        if (right < ps.front() || left > ps.back())
        {
            return 0;
        }

        auto lit = std::lower_bound(std::begin(ps), std::end(ps), left);
        auto rit = std::lower_bound(std::begin(ps), std::end(ps), right);

        if (rit == std::end(ps) || *rit > right)
        {
            --rit;
        }

        if (lit <= rit)
        {
            return std::distance(lit, rit) + 1;
        }

        return 0;
    }

private:
    std::unordered_map<int, std::vector<int>> vtp;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */