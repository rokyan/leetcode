// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/description/

class Solution
{
public:
    int maximumLength(std::string s)
    {
        auto res = -1;

        for (auto c = 'a'; c <= 'z'; c++)
        {
            std::vector<int> lens;
            auto cur = 0;

            for (auto i = 0; i < std::size(s); i++)
            {
                if (s[i] == c)
                {
                    cur++;
                }
                else
                {
                    if (cur > 0)
                    {
                        lens.push_back(cur);
                        cur = 0;
                    }
                }
            }

            if (cur > 0)
            {
                lens.push_back(cur);
            }

            std::unordered_map<int, int> cnt;

            for (auto len : lens)
            {
                if (len <= res)
                {
                    continue;
                }
                
                cnt[len]++;

                if (len > 1)
                {
                    cnt[len - 1] += 2;
                }

                if (len > 2)
                {
                    cnt[len - 2] += 3;
                }
            }

            for (const auto& entry : cnt)
            {
                if (entry.second >= 3)
                {
                    res = std::max(res, entry.first);
                }
            }
        }

        return res;
    }
};