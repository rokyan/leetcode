// https://leetcode.com/problems/remove-k-balanced-substrings/description/

class Solution
{
public:
    std::string removeSubstring(const std::string& s, int k)
    {
        const int n = s.size();

        std::vector<std::pair<char, int>> st;
        st.reserve(n);

        for (char c : s)
        {
            if (!st.empty() && st.back().first == c)
            {
                st.back().second++;
            }
            else
            {
                st.emplace_back(c, 1);
            }

            if (st.back().first == ')' && st.back().second == k)
            {
                if (st.size() == 1)
                {
                    continue;
                }

                if (st[st.size() - 2].second >= k)
                {
                    st.pop_back();

                    st.back().second -= k;

                    if (st.back().second == 0)
                    {
                        st.pop_back();
                    }
                }
            }
        }

        std::string res;
        res.reserve(st.size());

        for (const auto& e : st)
        {
            res += std::string(e.second, e.first);
        }

        return res;
    }
};