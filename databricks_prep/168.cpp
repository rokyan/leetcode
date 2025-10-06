class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        std::string res;

        while (columnNumber > 0)
        {
            res.push_back('A' + --columnNumber % 26);
            columnNumber /= 26;
        }

        std::ranges::reverse(res);

        return res;
    }
};