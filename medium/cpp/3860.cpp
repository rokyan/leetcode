// https://leetcode.com/problems/unique-email-groups/description/

class Solution
{
public:
    int uniqueEmailGroups(const std::vector<std::string>& emails)
    {
        std::unordered_set<std::string> un;

        for (const std::string& email : emails)
        {
            un.insert(normalize(email));
        }

        return un.size();
    }

private:
    std::string normalize(const std::string& email)
    {
        bool seenAt = false;
        bool seenPlus = false;
        std::string normalizedEmail;
        normalizedEmail.reserve(email.size());

        for (char c : email)
        {
            if (c == '+')
            {
                seenPlus = true;
            }
            else if (c == '@')
            {
                seenAt = true;
                normalizedEmail.push_back('@');
            }
            else if (c != '.' || c == '.' && seenAt)
            {
                if (seenAt || !seenPlus)
                {
                    normalizedEmail.push_back(std::tolower(c));
                }
            }
        }

        return normalizedEmail;  
    }
};