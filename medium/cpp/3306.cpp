// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/

class Solution
{
public:
    long long countOfSubstrings(const std::string& word, int k)
    {
        constexpr std::string_view vowels = "aeiou";

        std::array<int, 26> freq{ 0 };
        auto d = 0;

        auto cnt = 0;

        const auto n = std::size(word);

        auto res = 0LL;

        std::vector<int> c(n);

        for (auto i = static_cast<int>(n) - 1; i >= 0; i--)
        {
            if (vowels.find(word[i]) != std::string_view::npos)
            {
                c[i] = 1 + (i + 1 < n ? c[i + 1] : 0);
            }
        }

        for (auto l = 0, r = 0; l < n; l++)
        {
            while (r < n && cnt < k)
            {
                if (vowels.find(word[r]) == std::string_view::npos)
                {
                    cnt++;
                }
                else
                {
                    if (freq[word[r] - 'a']++ == 0)
                    {
                        d++;
                    }
                }

                r++;
            }

            if (cnt < k)
            {
                break;
            }

            while (r < n && d < 5 && vowels.find(word[r]) != std::string_view::npos)
            {
                if (freq[word[r] - 'a']++ == 0)
                {
                    d++;
                }

                r++;
            }

            if (d == 5)
            {
                res += 1 + (r < n ? c[r] : 0);
            }

            if (vowels.find(word[l]) == std::string_view::npos)
            {
                cnt--;
            }
            else
            {
                if (freq[word[l] - 'a']-- == 1)
                {
                    d--;
                }
            }
        }

        return res;
    }
};