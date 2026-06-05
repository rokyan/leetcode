// https://leetcode.com/problems/password-strength/description/

class Solution {
public:
    int passwordStrength(const std::string& password) {
        int res = 0;
        std::unordered_set<char> seen;

        for (char c : password) {
            if (!seen.insert(c).second) {
                continue;
            }

            if (c >= 'a' && c <= 'z') {
                res++;
            }
            else if (c >= 'A' && c <= 'Z') {
                res += 2;
            }
            else if (c >= '0' && c <= '9') {
                res += 3;
            }
            else
            {
                res += 5;
            }
        }

        return res;
    }
};