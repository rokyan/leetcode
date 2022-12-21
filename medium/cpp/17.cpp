// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution
{
private:
    std::map<char, std::string> mapping
    {
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" }
    };
    
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty()) {
            return {};
        }
        
        solve(0, digits);
        
        return solutions;
    }

private:
    void solve(std::size_t pos, const std::string& digits)
    {
        if (pos == digits.size())
        {
            solutions.push_back(solution);
        }
        
        const std::string& letters = mapping[digits[pos]];
        
        for (auto letter : letters)
        {
            solution.push_back(letter);
            solve(pos + 1, digits);
            solution.pop_back();
        }
    }

private:
    std::vector<std::string> solutions;
    std::string solution;
};