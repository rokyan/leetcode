// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

class Solution
{
public:
    std::string removeOccurrences(const std::string& s,
        const std::string& part)
    {
        const int m = part.size();
        const int n = s.size();

        std::vector<int> pref(n + m + 1);
    
        std::string res;
        res.reserve(s.size());
        res.push_back(part[0]);

        auto getSymbol = [&part, &s, m](int pos)
        {
            if (pos < m)
            {
                return part[pos];
            }

            if (pos == m)
            {
                return '#';
            }

            return s[pos - m - 1];
        };

        for (int i = 1; i < n + m + 1; i++)
        {
            int j = pref[res.size() - 1];
            char c = getSymbol(i);

            while (j > 0 && res[j] != c)
            {
                j = pref[j - 1];
            }

            if (res[j] == c)
            {
                j++;
            }

            res.push_back(c);
            pref[res.size() - 1] = j;

            if (j == m)
            {
                for (int t = 0; t < m; t++)
                {
                    res.pop_back();
                }
            }
        }

        return res.substr(m + 1);
    }
};