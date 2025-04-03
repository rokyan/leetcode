class Solution
{
public:
    bool isIsomorphic(const std::string& s, const std::string& t)
    {
        std::array<char, 256> mapping;
        mapping.fill(-1);

        const auto n = std::size(s);

        for (auto i = 0; i < n; i++)
        {
            if (mapping[s[i]] == -1)
            {
                for (auto j = 0; j < 256; j++)
                {
                    if (mapping[j] == t[i])
                    {
                        return false;
                    }
                }

                mapping[s[i]] = t[i];
            }
            else if (mapping[s[i]] != t[i])
            {
                return false;
            }
        }

        return true;
    }
};