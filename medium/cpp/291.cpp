// https://leetcode.com/problems/word-pattern-ii/description/

class Solution
{
public:
    bool wordPatternMatch(std::string pattern, std::string s)
    {
        return solve(pattern, 0, s, 0);
    }

private:
    bool solve(const std::string& pattern, int pattern_pos, const std::string& s, int s_pos)
    {
        if (pattern_pos == std::size(pattern))
        {
            if (s_pos == std::size(s))
            {
                return true;
            }

            return false;
        }

        if (const auto it = mapping.find(pattern[pattern_pos]); it != std::end(mapping))
        {
            const auto& sub = it->second;

            if (s_pos + std::size(sub) - 1 < std::size(s) && s.substr(s_pos, std::size(sub)) == sub)
            {
                return solve(pattern, pattern_pos + 1, s, s_pos + std::size(sub));
            }
            else
            {
                return false;
            }
        }
        else
        {
            auto res = false;

            for (auto i = s_pos; i < std::size(s) && !res; i++)
            {
                const auto sub = s.substr(s_pos, i - s_pos + 1);

                auto skip = false;

                for (const auto& e : mapping)
                {
                    if (e.second == sub)
                    {
                        skip = true;
                        break;
                    }
                }

                if (skip)
                {
                    continue;
                }

                mapping[pattern[pattern_pos]] = sub;

                res |= solve(pattern, pattern_pos + 1, s, s_pos + std::size(sub));

                mapping.erase(pattern[pattern_pos]);
            }

            return res;
        }
    }

private:
    std::unordered_map<char, std::string> mapping;
};