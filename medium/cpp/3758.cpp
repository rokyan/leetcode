// https://leetcode.com/problems/convert-number-words-to-digits/description/

class Solution
{
public:
    std::string convertNumber(const std::string& s)
    {
        const std::string_view sview{s};

        std::unordered_map<std::string_view, int> sti
        {
            {"zero", 0},
            {"one", 1},
            {"two", 2},
            {"three", 3},
            {"four", 4},
            {"five", 5},
            {"six", 6},
            {"seven", 7},
            {"eight", 8},
            {"nine", 9}
        };

        const int n = std::size(s);
        int p = 0;

        std::string res;

        while (p < n)
        {
            const int rem = n - p;
            bool found = false;

            for (const auto& [sr, val] : sti)
            {
                if (rem >= std::size(sr) && sview.substr(p, std::size(sr)) == sr)
                {
                    p += std::size(sr);
                    res += std::to_string(val);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                p++;
            }
        }

        return res;
    }
};