class TicTacToe
{
public:
    TicTacToe(int n)
        :n{n},
        d{0}
        ,ad{0}
    {
        rval.resize(n);
        cval.resize(n);
    }
    
    int move(int row, int col, int player)
    {
        const auto val = player == 1 ? 1 : -1;
        rval[row] += val;
        cval[col] += val;

        if (row == col)
        {
            d += val;
        }

        if (row == n - 1 - col)
        {
            ad += val;
        }

        if (std::abs(rval[row]) == n || std::abs(cval[col]) == n
            || abs(d) == n || abs(ad) == n)
        {
            return player;
        }

        return 0;
    }

private:
    int n;
    int d;
    int ad;
    std::vector<int> rval;
    std::vector<int> cval;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */