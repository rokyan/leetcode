// https://leetcode.com/problems/replace-the-substring-for-balanced-string/

class Solution
{
public:
    int balancedString(std::string s)
    {
        const auto n = static_cast<int>(std::size(s));

        std::unordered_map<char, int> mapping
        {
            {'Q', 0 },
            {'W', 1 },
            {'E', 2 },
            {'R', 3 },
        };

        std::array<int, 4> ntr{ 0 };

        for (auto c : s)
        {
            ntr[mapping[c]]++;
        }

        for (auto c = 0; c < 4; c++)
        {
            ntr[c] = std::max(0, ntr[c] - n / 4);
        }

        std::array<int, 4> cnt{ 0 };

        auto res = 0;

        for (auto l = 0, r = 0; r < n; r++)
        {
            cnt[mapping[s[r]]]++;

            while (cnt[mapping[s[l]]] > ntr[mapping[s[l]]])
            {
                cnt[mapping[s[l++]]]--;
            }

            auto matched = true;

            for (auto c = 0; c < 4; c++)
            {
                if (cnt[c] < ntr[c])
                {
                    matched = false;
                    break;
                }
            }

            if (matched)
            {
                res = res == 0 ? r - l + 1 : std::min(res, r - l + 1);
            }
        }

        return res;
    }
};