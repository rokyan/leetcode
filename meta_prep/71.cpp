class Solution
{
public:
    std::string simplifyPath(const std::string& path)
    {
        std::string dir;
        std::vector<std::string> st;

        auto handle = [&st, &dir]()
        {
            if (!dir.empty())
            {
                if (dir == "..")
                {
                    if (!st.empty()) st.pop_back();
                }
                else if (dir != ".")
                {
                    st.push_back(dir);
                }

                dir.clear();
            }
        };

        for (auto i = 0; i < std::size(path); i++)
        {
            if (path[i] == '/')
            {
                handle();
            }
            else
            {
                dir.push_back(path[i]);
            }
        }

        handle();

        if (st.empty())
        {
            return "/";
        }

        std::string canonical;
        canonical.reserve(std::size(path));

        for (const auto& dir : st)
        {
            canonical.push_back('/');
            canonical += dir;
        }

        return canonical;
    }
};