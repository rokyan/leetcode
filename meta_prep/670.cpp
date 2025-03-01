class Solution
{
public:
    int maximumSwap(int num)
    {
        auto str = std::to_string(num);
        auto res = str;

        const int n = std::size(str);
        auto pos = n - 1;

        for (auto i = n - 1; i >= 0; i--)
        {
            if (str[i] < str[pos])
            {
                std::swap(str[i], str[pos]);
                res = std::max(res, str);
                std::swap(str[i], str[pos]);
            }
            else if (str[i] > str[pos])
            {
                pos = i;
            }
        }

        return std::stoi(res);
    }
};