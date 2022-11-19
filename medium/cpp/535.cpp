// https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution
{
private:
    static constexpr std::size_t URL_LENGTH = 6;
    static constexpr std::size_t AVAIL_SYM_COUNT = 10 + 26 * 2;
    
public:
    Solution()
        : gen(std::random_device{}())
        , distr(0, AVAIL_SYM_COUNT)
    {
        generateAllSymbols();
    }
       
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        const auto it = longToShort.find(longUrl);
        
        if (it != std::end(longToShort))
        {
            return it->second;
        }
        
        const auto shortUrl = generateShortUrl();
        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;
        
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return shortToLong.find(shortUrl)->second;
    }
    
private:
    void generateAllSymbols()
    {
        for (auto c = '0'; c <= '9'; c++)
        {
           allSymbols += c; 
        }
        
        for (auto c = 'a'; c <= 'z'; c++)
        {
           allSymbols += c; 
        }
        
        for (auto c = 'A'; c <= 'Z'; c++)
        {
           allSymbols += c; 
        }
    }
    
    std::string generateShortUrl()
    {
        std::string shortUrl;
        shortUrl.resize(URL_LENGTH);
        
        for (std::size_t pos = 0; pos < URL_LENGTH; pos++)
        {
            shortUrl[pos] = allSymbols[distr(gen)];
        }
        
        return shortUrl;
    }
    
private:
    std::mt19937 gen;
    std::uniform_int_distribution<> distr;
    
    std::string allSymbols;
    
    std::unordered_map<std::string, std::string> longToShort;
    std::unordered_map<std::string, std::string> shortToLong;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));