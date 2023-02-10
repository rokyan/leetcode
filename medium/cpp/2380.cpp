// https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/description/

class Solution
{
public:
    int secondsToRemoveOccurrences(std::string s)
    {
        const auto n = static_cast<int>(std::size(s));

        auto res = 0;

        for (;;)
        {
            auto swapped = false;

            for (auto i = 0; i + 1 < n; )
            {
                if (s[i] == '0' && s[i + 1] == '1')
                {
                    std::swap(s[i], s[i + 1]);
                    
                    swapped = true;

                    i += 2;
                }
                else
                {
                    i++;
                }
            }

            if (!swapped)
            {
                break;
            }

            res++;
        }

        return res;
    }
};