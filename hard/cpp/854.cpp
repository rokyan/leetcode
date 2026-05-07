// https://leetcode.com/problems/k-similar-strings/description/

class Solution
{
public:
    int kSimilarity(string s1, string s2)
    {
        if (s1 == s2)
        {
            return 0;
        }
        
        std::queue<std::string> q;
        std::unordered_set<std::string> seen;
        
        q.push(s1);
        seen.insert(s1);
        
        for (int step = 0; !q.empty(); ++step)
        {
            const int sz = q.size();

            for (int i = 0; i < sz; ++i)
            {
                std::string curr = q.front();
                q.pop();
                
                if (curr == s2)
                {
                    return step;
                }
                
                for (const std::string& next : getNext(curr, s2))
                {
                    if (seen.find(next) == seen.end())
                    {
                        seen.insert(next);
                        q.push(next);
                    }
                }
            }
        }

        return -1;      
    }

private:
    std::vector<std::string> getNext(std::string curr, const std::string& target)
    {
        std::vector<std::string> children;
        
        int i = 0;
        while (i < curr.size() && curr[i] == target[i])
        {
            i++;
        }
        
        for (int j = i + 1; j < curr.size(); ++j)
        {
            if (curr[j] == target[i])
            {
                std::swap(curr[i], curr[j]);
                children.push_back(curr);
                std::swap(curr[i], curr[j]);
            }
        }
        return children;
    }
};