// https://leetcode.com/problems/repeated-dna-sequences/description/

class Solution 
{
private:
    static constexpr auto window_size = 10;

public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s)
    {
        const auto n = std::size(s);

        if (n < window_size)
        {
            return {};
        }

        std::map<std::string_view, int> cnt;
        const auto view = std::string_view{ s };

        for (auto i = 0; i + window_size - 1 < n; i++)
        {
            cnt[view.substr(i, window_size)]++;
        }

        std::vector<std::string> res;
        res.reserve(std::size(cnt));

        for (const auto& entry : cnt)
        {
            if (entry.second > 1)
            {
                res.push_back(std::string{ entry.first });
            }
        }

        return res;
    }
};