// https://leetcode.com/problems/unique-word-abbreviation/description/

class ValidWordAbbr
{
public:
    ValidWordAbbr(const std::vector<std::string>& dictionary)
    {
        for (const std::string& word : dictionary)
        {
            abbrToWords[abbreviate(word)].insert(word);
        }
    }
    
    bool isUnique(const std::string& word)
    {
        if (const auto it = abbrToWords.find(abbreviate(word)); it != std::end(abbrToWords))
        {
            return std::size(it->second) == 1 && it->second.count(word) > 0;
        }

        return true;
    }

private:
    std::string abbreviate(const std::string& word)
    {
        const int len = std::size(word);

        if (len <= 2)
        {
            return word;
        }

        return word.front() + std::to_string(len - 2) + word.back();
    }

private:
    std::unordered_map<std::string, std::unordered_set<std::string>> abbrToWords;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */