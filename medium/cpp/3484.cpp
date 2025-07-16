// https://leetcode.com/problems/design-spreadsheet/description/

class Spreadsheet
{
public:
    Spreadsheet(int rows)
    {
        data.resize(rows + 1);
    }
    
    void setCell(const std::string& cell, int value)
    {
        const auto [row, col] = parse(cell);

        if (data[row].empty())
        {
            data[row].resize(26);
        }

        data[row][col] = value;
    }
    
    void resetCell(const std::string& cell)
    {
        const auto [row, col] = parse(cell);

        if (data[row].empty())
        {
            return;
        }

        data[row][col] = 0;
    }
    
    int getValue(const std::string& formula)
    {
        return eval(formula);
    }

private:
    std::pair<int, int> parse(const std::string& cell)
    {
        auto col = cell[0] - 'A';
        auto row = 0;

        for (auto i = 1; i < std::size(cell); i++)
        {
            row = 10 * row + cell[i] - '0';
        }

        return {row, col};
    }

    int getVal(const std::string& expr)
    {
        if (expr[0] >= 'A' && expr[0] <= 'Z')
        {
            const auto [row, col] = parse(expr);
            return data[row].empty() ? 0 : data[row][col];
        }

        auto val = 0;

        for (auto i = 0; i < std::size(expr); i++)
        {
            val = 10 * val + expr[i] - '0';
        }

        return val;
    }

    int eval(const std::string& expr)
    {
        auto i = 0;

        while (expr[i] != '+')
        {
            i++;
        }

        return getVal(expr.substr(1, i - 1)) + getVal(expr.substr(i + 1));
    }

private:
    std::vector<std::vector<int>> data;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */