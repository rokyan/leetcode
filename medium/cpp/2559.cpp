// https://leetcode.com/problems/count-vowel-strings-in-ranges/description/

class Solution
{
public:
    std::vector<int> vowelStrings(std::vector<std::string>& words, std::vector<std::vector<int>>& queries)
    {
        const std::string vowels { "aeiou" };

        const auto words_tot = std::size(words);

        std::vector<int> pref_sum(words_tot);

        for (auto idx = 0; idx < words_tot; idx++)
        {
            pref_sum[idx] = vowels.find(words[idx].front()) != std::string::npos &&
                vowels.find(words[idx].back()) != std::string::npos;

            if (idx > 0)
            {
                pref_sum[idx] += pref_sum[idx - 1];
            }
        }

        const auto queries_tot = std::size(queries);

        std::vector<int> res(queries_tot);

        for (auto idx = 0; idx < queries_tot; idx++)
        {
            const auto left = queries[idx][0];
            const auto right = queries[idx][1];

            auto cnt = pref_sum[right];

            if (left > 0)
            {
                cnt -= pref_sum[left - 1];
            }

            res[idx] = cnt;
        }

        return res;
    }
};