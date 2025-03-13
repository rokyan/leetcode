class Solution
{
public:     
    std::vector<std::string> generateParenthesis(int n)
    {
        seq.resize(2 * n);

        generate(0, 0, n);

        return ans;
    }

private:
   void generate(int opened, int closed, int n)
   {
        if (opened == n && closed == n)
        {
            ans.push_back(seq);
            return;
        }
        
        if (opened < n)
        {
            seq[opened + closed] = '(';
            generate(opened + 1, closed, n);
        }
        
        if (closed < opened)
        {
            seq[opened + closed] = ')';
            generate(opened, closed + 1, n);
        }
    }

private:
    std::string seq;
    std::vector<std::string> ans;
};