// https://leetcode.com/problems/rearrange-k-substrings-to-form-target-string/description/

class Solution
{
public:
    bool isPossibleToRearrange(const std::string s, const std::string t, int k)
    {
        std::unordered_map<std::string_view, int> freq;
        std::string_view sw{std::begin(s), std::end(s)};

        k = std::size(s) / k;

        for (auto i = 0; i < std::size(s); )
        {
            freq[sw.substr(i, k)]++;
            i += k;
        }

        std::string_view sw2{std::begin(t), std::end(t)};

        for (auto i = 0; i < std::size(t); )
        {
            const auto it = freq.find(sw2.substr(i, k));

            if (it == std::end(freq) || it->second == 0)
            {
                return false;
            }

            it->second--;
            i += k;
        }

        return true;
    }
};