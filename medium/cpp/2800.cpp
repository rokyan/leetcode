// https://leetcode.com/problems/shortest-string-that-contains-three-strings/description/

class Solution
{
public:
    string minimumString(string a, string b, string c)
    {
        std::vector<std::string> strs{ a, b, c };

        std::sort(std::begin(strs), std::end(strs));

        std::string res;

        do
        {
            auto cur = strs[0];

            for (auto i = 1; i < 3; i++)
            {
                if (cur.find(strs[i]) != std::string::npos)
                {
                    continue;
                }

                auto b_len = 0;


                for (auto len = 1; len < std::min(std::size(cur), std::size(strs[i])); len++)
                {
                    if (cur.substr(std::size(cur) - len) == strs[i].substr(0, len))
                    {
                        b_len = len;
                    }
                }

                cur += strs[i].substr(b_len);
            }

            if (res.empty() || std::size(cur) < std::size(res) || std::size(cur) == std::size(res) && cur < res)
            {
                res = cur;
            }
        }
        while (std::next_permutation(std::begin(strs), std::end(strs)));

        return res;
    }
};