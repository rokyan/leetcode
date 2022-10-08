// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

class Solution
{
public:
    std::vector<int> numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words)
    {      
        std::vector<int> acc(10 + 2);
        
        std::for_each(std::begin(words), std::end(words), [&acc](const std::string& word) {
            acc[f(word)]++;
        });
        
        for (int i = 9; i >= 0; i--)
        {
            acc[i] += acc[i + 1];
        }
        
        const auto m = std::size(queries);
        
        std::vector<int> res(m);
        
        for (std::size_t q = 0; q < m; q++)
        {
            const auto freq = f(queries[q]);
            
            res[q] = acc[freq + 1];
        }
        
        return res;
    }
    
private:
    static int f(const std::string& s)
    {       
        return std::count(std::begin(s), std::end(s), *std::min_element(std::begin(s), std::end(s)));
    }
};