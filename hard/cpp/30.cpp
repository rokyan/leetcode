// https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

class Solution
{
public:
    std::vector<int> findSubstring(const std::string& s, const std::vector<std::string>& words)
    {
        std::unordered_map<std::string_view, int> freq;

        for (const auto& word : words)
        {
            freq[word]++;
        }

        const auto n = std::size(s);
        const auto wlen = std::size(words.front());
        const auto len = std::size(words) * wlen;
        const auto sw = std::string_view{s};

        std::vector<int> res;

        for (auto i = len - 1; i < n; i++)
        {
            auto times = static_cast<int>(std::size(words));
            auto pos = i;
            auto cfreq = freq;

            while (times--)
            {
                const auto cur = sw.substr(pos - wlen + 1, wlen);

                if (auto it = cfreq.find(cur); it != std::end(cfreq) && it->second > 0)
                {
                    it->second--;
                }
                else
                {
                    break;
                }

                pos -= wlen;
            }

            if (times == -1)
            {
                res.push_back(i - len + 1);
            }
        }

        return res;
    }
};