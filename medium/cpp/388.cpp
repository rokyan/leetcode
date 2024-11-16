// https://leetcode.com/problems/longest-absolute-file-path/description/

class Solution
{
public:
    int lengthLongestPath(const std::string& input)
    {
        auto len = 0;

        std::vector<int> st;

        const auto n = std::size(input);

        auto res = 0;

        for (auto i = 0; i < n; )
        {
            if (i < n && input[i] == '\n')
            {
                i++;
            }

            auto cur_depth = 1;

            while (i < n && input[i] == '\t')
            {
                cur_depth++;
                i++;
            }

            auto cur_len = 0;
            auto is_file = false;

            while (i < n && input[i] != '\n')
            {
                cur_len++;

                if (input[i++] == '.')
                {
                    is_file = true;
                }
            }

            while (!st.empty() && std::size(st) >= cur_depth)
            {
                len -= st.back();
                st.pop_back();
            }

            st.push_back(cur_len);
            len += cur_len;

            if (is_file)
            {
                res = std::max<int>(res, len + std::size(st) - 1);
            }
        }

        return res;
    }
};