class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        s.erase(std::remove_if(std::begin(s), std::end(s), [](char c) {
            return !std::isalnum(c);
        }), std::end(s));

        std::transform(std::begin(s), std::end(s), std::begin(s), [](char c) {
            return std::tolower(c);
        });

        const auto len = std::size(s);

        return std::equal(std::begin(s), std::next(std::begin(s), len / 2), std::rbegin(s));
    }
};