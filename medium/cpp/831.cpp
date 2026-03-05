class Solution
{
public:
    std::string maskPII(const std::string& s)
    {
        if (isEmail(s))
        {
            return maskEmail(s);
        }
        else
        {
            return maskPhone(s);
        }
    }

private:
    bool isEmail(const std::string& s)
    {
        return std::isalpha(s.front());
    }

    std::string maskEmail(const std::string& s)
    {
        const int n = s.size();
        std::string masked;
        masked.reserve(n);

        bool seenAt = false;

        for (int i = 0; i < n; i++)
        {
            if (seenAt)
            {
                masked.push_back(std::tolower(s[i]));
            }
            else if (s[i] == '@')
            {
                masked += "*****";
                masked.push_back(std::tolower(s[i - 1]));
                masked.push_back('@');
                seenAt = true;
            }
            else if (i == 0)
            {
                masked.push_back(std::tolower(s[i]));
            }
        }

        return masked;
    }

    std::string maskPhone(const std::string& s)
    {
        const int n = s.size();
        int digitsCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (std::isdigit(s[i]))
            {
                digitsCount++;
            }
        }

        std::string masked;

        if (digitsCount == 10)
        {
            masked = "***-***-";
        }
        else if (digitsCount == 11)
        {
            masked = "+*-***-***-";
        }
        else if (digitsCount == 12)
        {
            masked = "+**-***-***-";
        }
        else // if (digits == 13)
        {
            masked = "+***-***-***-";
        }

        for (int i = 0; i < n; i++)
        {
            if (std::isdigit(s[i]))
            {
                if (digitsCount-- <= 4)
                {
                    masked.push_back(s[i]);
                }
            }
        }

        return masked;
    }
};