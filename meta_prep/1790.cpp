class Solution
{
public:
    bool areAlmostEqual(const std::string& s1, const std::string& s2)
    {
        const auto n = std::size(s1);

        if (n == 1)
        {
            return s1[0] == s2[0];
        }

        auto p1 = -1;
        auto p2 = -1;

        for (auto i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                if (p1 == -1)
                {
                    p1 = i;
                }
                else if (p2 == -1)
                {
                    p2 = i;
                }
                else
                {
                    return false;
                }
            }
        }

        if (p1 == -1)
        {
            return true;
        }

        if (p2 == -1)
        {
            return false;
        }

        return s1[p1] == s2[p2] &&
            s1[p2] == s2[p1];
    }
};