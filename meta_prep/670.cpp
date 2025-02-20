class Solution
{
public:
    int maximumSwap(int num)
    {
        auto str = std::to_string(num);

        std::array<int, 10> first;
        first.fill(-1);

        std::string res{str};

        for (auto i = 0; i < std::size(str); i++)
        {
            const auto digit = str[i] - '0';

            for (auto cand = 0; cand < digit; cand++)
            {
                if (first[cand] != -1)
                {
                    std::swap(str[first[cand]], str[i]);
                    res = std::max(res, str);
                    std::swap(str[first[cand]], str[i]);
                }
            }

            if (first[digit] == -1)
            {
                first[digit] = i;
            }
        }

        return std::stoi(res);
    }
};