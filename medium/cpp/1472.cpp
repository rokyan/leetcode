// https://leetcode.com/problems/design-browser-history/

class BrowserHistory
{
public:
    BrowserHistory(std::string homepage)
        : pointer(0)
    {
        pages.push_back(homepage);
    }
    
    void visit(std::string url)
    {        
        pages.erase(std::begin(pages) + pointer + 1, std::end(pages));
        
        pages.push_back(url);
        
        
        pointer++;
    }
    
    std::string back(int steps)
    {
        steps = std::min(steps, pointer);
        
        pointer -= steps;
        
        return pages[pointer];
    }
    
    std::string forward(int steps)
    {
        steps = min(steps, static_cast<int>(std::size(pages)) - pointer - 1);
        
        pointer += steps;
        
        return pages[pointer];
    }
    
private:
    std::vector<std::string> pages;
    int pointer;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */