// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/

class Solution
{
public:
    int maxLength(const std::vector<std::string>& arr)
    {
        const int n = arr.size();

        std::array<int, 26> cnt;
        int res = 0;

        for (int mask = 0; mask < (1 << n); mask++)
        {
            cnt.fill(0);
            bool qualifies = true;
            int total_len = 0;

            for (int i = 0; i < n && qualifies; i++)
            {
                if (mask & (1 << i))
                {
                    for (char c : arr[i])
                    {
                        if (cnt[c - 'a']++ > 0)
                        {
                            qualifies = false;
                            break;
                        }

                        total_len++;
                    }
                }
            }

            if (qualifies)
            {
                res = std::max(res, total_len);
            }
        }

        return res;
    }
};