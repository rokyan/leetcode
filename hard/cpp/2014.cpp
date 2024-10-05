https://leetcode.com/problems/longest-subsequence-repeated-k-times/description/

class Solution
{
private:
    static constexpr auto max_len = 7;

public:
    std::string longestSubsequenceRepeatedK(const std::string& s, int k)
    {
        std::array<int, 26> freq{ 0 };

        for (auto c : s)
        {
            freq[c - 'a']++;
        }

        for (auto len = std::size(s) / k; len >= 1; len--)
        {
            std::string acc;
            std::string res;

            if (solve(len, s, k, freq, acc, res))
            {
                return res;
            }
        }

        return "";
    }

private:
    bool solve(int len, const std::string& s, int k, std::array<int, 26>& freq, std::string acc, std::string& res)
    {
        if (len == 0)
        {
            if (find_k_times(s, acc, k))
            {
                res = acc;
                return true;
            }

            return false;
        }
        else
        {
            for (auto c = 25; c >= 0; c--)
            {
                if (freq[c] >= k)
                {
                    freq[c] -= k;
                    acc.push_back(c + 'a');
                    const auto found = solve(len - 1, s, k, freq, acc, res);
                    acc.pop_back();
                    freq[c] += k;

                    if (found)
                    {
                        return true;
                    }
                }
            }

            return false;
        }
    }

    bool find_k_times(const std::string& s, const std::string& pattern, int k)
    {
        for (auto i = 0, p = 0; i < std::size(s) && k; i++)
        {
            if (s[i] == pattern[p])
            {
                if (++p == std::size(pattern))
                {
                    k--;
                    p = 0;
                }
            }
        }

        return !k;
    }
};