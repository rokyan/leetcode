// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/

class Solution
{
public:
    int takeCharacters(std::string s, int k)
    {
        const auto n = static_cast<int>(std::size(s));

        std::vector<std::vector<int>> pref(3, std::vector<int>(n + 1));

        for (auto i = 1; i <= n; i++)
        {
            pref[s[i - 1] - 'a'][i]++;

            for (auto j = 0; j < 3; j++)
            {
                pref[j][i] += pref[j][i - 1];
            }
        }

        int pos[3] { -1 };

        for (auto j = 0; j < 3; j++)
        {
            pos[j] = get(std::cbegin(pref[j]), std::cend(pref[j]), k);

            if (pos[j] == -1)
            {
                return -1;
            }
        }

        auto res = *std::max_element(std::cbegin(pos), std::cend(pos));

        int cnt[3] { k, k, k };

        for (auto i = n, taken = 1; i > 0; i--, taken++)
        {
            cnt[s[i - 1] - 'a']--;

            for (auto j = 0; j < 3; j++)
            {
                pos[j] = get(std::cbegin(pref[j]), std::begin(pref[j]) + i - 1, cnt[j]);
            }

            if (pos[0] == -1 || pos[1] == -1 || pos[2] == -1)
            {
                continue;
            }

            const auto updated = *std::max_element(std::cbegin(pos), std::cend(pos));

            res = std::min(res, updated + taken);
        }

        return res;
    }

private:
    int get(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last, int value)
    {
        const auto it = std::lower_bound(first, last, value);

        return (it == last) ? -1 : std::distance(first, it);
    }
};