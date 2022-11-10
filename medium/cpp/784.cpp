// https://leetcode.com/problems/letter-case-permutation/

class Solution
{
public:
    std::vector<std::string> letterCasePermutation(std::string s)
    {
        std::vector<string> answers;
        
        solve(s, 0, answers);
        
        return answers;
    }
    
private:
    void solve(std::string& s, std::size_t pos, std::vector<std::string>& answers)
    {
        if (pos == std::size(s))
        {
            answers.push_back(s);
            return;
        }
        
        if (std::isalpha(s[pos]))
        {
            s[pos] = std::tolower(s[pos]);
            solve(s, pos + 1, answers);
            
            s[pos] = std::toupper(s[pos]);
            solve(s, pos + 1, answers);
        }
        else
        {
            solve(s, pos + 1, answers);
        }
    }
};