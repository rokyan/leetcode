// https://leetcode.com/problems/rearrange-string-k-distance-apart/

class Solution
{
public:
    std::string rearrangeString(std::string s, int k)
    {
        k = std::max(k, 1);

        std::array<int, 26> cnt{ 0 };

        for (auto c : s)
        {
            cnt[c - 'a']++;
        }

        std::priority_queue<std::pair<int, char>> pq;

        for (auto c = 0; c < 26; c++)
        {
            if (cnt[c] > 0)
            {
                pq.push({ cnt[c], c + 'a' });
            }
        }

        const auto n = static_cast<int>(std::size(s));

        auto res = std::string{};
        res.reserve(n);

        std::vector<std::pair<int, char>> extracted;

        for (auto i = 0; i < n; )
        {
            auto times = std::min(n - i, k);
            i += times;

            while (times--)
            {
                if (pq.empty())
                {
                    return "";
                }

                auto e = pq.top();
                pq.pop();
                res.push_back(e.second);

                if (--e.first)
                {
                    extracted.push_back(std::move(e));
                }
            }

            for (auto& e : extracted)
            {
                pq.push(std::move(e));
            }

            extracted.clear();
        }

        return res;
    }
};