// https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/description/

class Solution
{
public:
    std::string minimizeStringValue(const std::string& s)
    {
        std::array<int, 26> freq{ 0 };

        for (auto c : s)
        {
            if (c != '?')
            {
                freq[c - 'a']++;
            }
        }

        std::vector<char> add;
        add.reserve(std::size(s));

        for (auto c : s)
        {
            if (c == '?')
            {
                auto last = 0;

                for (auto i = 0; i < 26; i++)
                {
                    if (freq[i] < freq[last])
                    {
                        last = i;
                    }
                }

                freq[last]++;
                add.push_back('a' + last);
            }
        }

        std::sort(std::begin(add), std::end(add));

        std::string res;
        res.reserve(std::size(s));

        auto pos = 0;

        for (auto c : s)
        {
            if (c == '?')
            {
                res.push_back(add[pos++]);
            }
            else
            {
                res.push_back(c);
            }
        }

        return res;
    }
};