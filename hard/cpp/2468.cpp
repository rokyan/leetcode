// https://leetcode.com/problems/split-message-based-on-limit/description/

class Solution
{
public:
    std::vector<std::string> splitMessage(const std::string& message, int limit)
    {
        const int n = std::size(message);

        for (int parts = 1; parts <= n; parts++)
        {
            const int partsNumLen = calcNumLen(parts);
            bool valid = true;
            int rem = n - parts;

            for (int id = 1; id <= parts; id++)
            {
                const int suffixLen = 3 + calcNumLen(id) + partsNumLen;

                if (suffixLen >= limit)
                {
                    valid = false;
                    break;
                }

                const int take = limit - suffixLen - 1;
                
                if (take > rem)
                {
                    if (id != parts)
                    {
                        valid = false;
                        break;
                    }
                }

                rem -= take;
            }

            if (rem > 0)
            {
                valid = false;
            }

            if (valid)
            {
                std::vector<std::string> res(parts);
                int pt = 0;

                for (int id = 1; id <= parts; id++)
                {
                    const std::string suffix = "<" + std::to_string(id) + "/" + std::to_string(parts) + ">";
                    int rem = limit - std::size(suffix);

                    res[id - 1].reserve(limit);
                    
                    while (rem > 0 && pt < std::size(message))
                    {
                        res[id - 1].push_back(message[pt++]);
                        rem--;
                    }

                    res[id - 1] += std::move(suffix);
                }

                return res;
            }
        }

        return {};
    }

private:
    int calcNumLen(int x)
    {
        int res = 0;

        while (x)
        {
            res++;
            x /= 10;
        }

        return res;
    }
};

// n parts
// len("<1/n>") + limit, len("<2/n>") + limit, ..., len("<n/n>") + k