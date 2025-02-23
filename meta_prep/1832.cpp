class Solution
{
public:
    bool checkIfPangram(const std::string& sentence)
    {
        std::array<bool, 26> probe;
        probe.fill(0);

        std::for_each(std::cbegin(sentence), std::cend(sentence), [&probe](auto c) {
            probe[c - 'a'] = true;
        });

        return std::all_of(std::cbegin(probe), std::cend(probe), [](auto c) {
            return c; });
    }
};