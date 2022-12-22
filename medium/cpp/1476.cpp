// https://leetcode.com/problems/subrectangle-queries/description/

class SubrectangleQueries
{
private:
    struct Op
    {
        Op(int row1, int col1, int row2, int col2, int val)
        {
            this->row1 = row1;
            this->col1 = col1;
            this->row2 = row2;
            this->col2 = col2;
            this->val = val;
        }

        int row1;
        int col1;
        int row2;
        int col2;
        int val;
    };

public:   
    SubrectangleQueries(std::vector<std::vector<int>>& rectangle)
        : rectangle(rectangle)
    { }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        ops.push_back(Op{ row1, col1, row2, col2, newValue });
    }
    
    int getValue(int row, int col)
    {
        auto val = rectangle[row][col];
        
        for (auto&& op : ops)
        {
            if (row >= op.row1 && row <= op.row2 && col >= op.col1 && col <= op.col2)
            {
                val = op.val;
            }
        }
        
        return val;
    }
    
private:   
    std::vector<std::vector<int>>& rectangle;
    std::vector<Op> ops;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */