class Solution
{
public:
    int romanToInt(const std::string& s)
    {
        std::unordered_map<char, int> mapping_single
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        std::unordered_map<std::string_view, int> mapping_double
        {
            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900},
        };

        auto res = 0;

        int n = std::size(s);
        std::string_view sw{s};

        for (auto i = n - 1; i >= 0; i--)
        {
            if (i > 0)
            {
                if (const auto it = mapping_double.find(sw.substr(i - 1, 2)); it != std::end(mapping_double))
                {
                    res += it->second;
                    i--;
                }
                else
                {
                    res += mapping_single[sw[i]];
                }
            }
            else
            {
                res += mapping_single[sw[i]];
            }
        }

        return res;
    }
};