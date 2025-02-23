class Solution
{
public:
    std::string removeDuplicates(const std::string& s)
    {
        std::string res;
        res.reserve(std::size(s));

        for (auto c : s)
        {
            if (res.empty() || res.back() != c)
            {
                res.push_back(c);
            }
            else
            {
                res.pop_back();
            }
        }

        return res;
    }
};