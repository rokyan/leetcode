// https://leetcode.com/problems/design-a-text-editor/description/

class TextEditor
{
public:
    TextEditor()
    {
        cursor = std::end(currentText);
    }
    
    void addText(const std::string& text)
    {
        for (auto c : text)
        {
            cursor = currentText.insert(cursor, c);
            ++cursor;
        }
    }
    
    int deleteText(int k)
    {
        auto deleted = 0;

        while (cursor != std::begin(currentText) && k--)
        {
            auto prev = std::prev(cursor);
            currentText.erase(prev);
            deleted++;
        }

        return deleted;
    }
    
    std::string cursorLeft(int k)
    {
        while (cursor != std::begin(currentText) && k--)
        {
            --cursor;
        }

        auto it = cursor;
        std::string res;
        auto take = 10;

        while (it != std::begin(currentText) && take--)
        {
            auto prev = std::prev(it);
            res.push_back(*prev);
            it = prev;
        }

        std::ranges::reverse(res);

        return res;
    }
    
    std::string cursorRight(int k)
    {
        while (cursor != std::end(currentText) && k--)
        {
            ++cursor;
        }

        auto it = cursor;
        std::string res;
        auto take = 10;

        while (it != std::begin(currentText) && take--)
        {
            auto prev = std::prev(it);
            res.push_back(*prev);
            it = prev;
        }

        std::ranges::reverse(res);

        return res;
    }

private:
    std::list<char> currentText;
    std::list<char>::iterator cursor;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */