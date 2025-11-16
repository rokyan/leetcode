// https://leetcode.com/problems/find-kth-character-in-expanded-string/description/

class Solution
{
public:
    char kthCharacter(const std::string& s, long long k)
    {
        int cnt = 1;
        k++;

        for (auto c : s)
        {
            if (c == ' ')
            {
                cnt = 1;

                if (cnt >= k)
                {
                    return c;
                }

                k--;
            }
            else
            {
                if (cnt >= k)
                {
                    return c;
                }

                k -= cnt++;
            }
        }

        return 'a';
    }
};