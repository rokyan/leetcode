// https://leetcode.com/problems/validate-ip-address/description/

class Solution
{
public:
    std::string validIPAddress(std::string queryIP)
    {
        auto times = std::count(std::cbegin(queryIP), std::cend(queryIP), '.');

        if (times == 3)
        {
            const auto parts = split(queryIP, '.');

            const auto res = std::all_of(std::cbegin(parts), std::cend(parts), validatePartV4);

            return res ? "IPv4" : "Neither";
        }

        times = std::count(std::cbegin(queryIP), std::cend(queryIP), ':');

        if (times == 7)
        {
            const auto parts = split(queryIP, ':');

            const auto res = std::all_of(std::cbegin(parts), std::cend(parts), validatePartV6);

            return res ? "IPv6" : "Neither";
        }

        return "Neither";
    }

private:
    static std::vector<std::string> split(const std::string& s, char delim)
    {
        std::vector<std::string> parts;
        auto acc = std::string{};

        for (auto c : s)
        {
            if (c == delim)
            {
                parts.push_back(acc);
                acc.clear();
            }
            else
            {
                acc.push_back(c);
            }
        }

        parts.push_back(acc);

        return parts;
    }

    static bool validatePartV4(const std::string& s)
    {
        if (s.empty() || s.front() == '0' && std::size(s) > 1)
        {
            return false;
        }

        auto num = 0;

        for (auto c : s)
        {
            if (c >= '0' && c <= '9' && num <= 255)
            {
                num = 10 * num + c - '0';
            }
            else
            {
                return false;
            }
        }

        return num <= 255;
    }

    static bool validatePartV6(const std::string& s)
    {
        if (s.empty() || std::size(s) > 4)
        {
            return false;
        }

        for (auto c : s)
        {
            if (c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F' || c >= '0' && c <= '9')
            {
                continue;
            }

            return false;
        }

        return true;
    }
};