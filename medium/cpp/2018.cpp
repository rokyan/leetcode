// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/description/

class Solution
{
public:
    bool placeWordInCrossword(
        std::vector<std::vector<char>>& board,
        std::string& word)
    {
        if (matchVertical(word, board))
        {
            return true;
        }

        reverseVertical(board);

        if (matchVertical(word, board))
        {
            return true;
        }

        reverseVertical(board);

        if (matchHorizontal(word, board))
        {
            return true;
        }

        reverseHorizontal(board);

        if (matchHorizontal(word, board))
        {
            return true;
        }

        return false;
    }

private:
    void reverseVertical(std::vector<std::vector<char>>& board)
    {
        const auto n = std::size(board);
        const auto m = std::size(board.front());

        for (auto c = 0; c < m; c++)
        {
            for (auto r = 0; r * 2 < n; r++)
            {
                std::swap(board[r][c], board[n - 1 - r][c]);
            }
        }
    }

    void reverseHorizontal(std::vector<std::vector<char>>& board)
    {
        const auto n = std::size(board);
        const auto m = std::size(board.front());

        for (auto r = 0; r < n; r++)
        {
            for (auto c = 0; c * 2 < m; c++)
            {
                std::swap(board[r][c], board[r][m - 1 - c]);
            }
        }
    }

    bool matchVertical(const std::string& word, const std::vector<std::vector<char>>& board)
    {
        const auto n = std::size(board);
        const auto m = std::size(board.front());

        const auto len = std::size(word);

        std::vector<int> cnt(m);

        for (auto r = 0; r <= n; r++)
        {
            for (auto c = 0; c < m; c++)
            {
                if (r == n || board[r][c] == '#')
                {
                    if (cnt[c] == len)
                    {
                        auto start = r - len;
                        auto pos = 0;
                        auto matched = true;

                        while (start < r && matched)
                        {
                            if (board[start][c] == ' ')
                            {
                                start++;
                                pos++;
                            }
                            else
                            {
                                if (board[start][c] == word[pos])
                                {
                                    start++;
                                    pos++;
                                }
                                else
                                {
                                    matched = false;
                                }
                            }
                        }

                        if (matched)
                        {
                            return true;
                        }
                    }

                    cnt[c] = 0;
                }
                else
                {
                    cnt[c]++;
                }
            }
        }

        return false;
    }

    bool matchHorizontal(const std::string& word, const std::vector<std::vector<char>>& board)
    {
        const auto n = std::size(board);
        const auto m = std::size(board.front());

        const auto len = std::size(word);

        std::vector<int> cnt(n);

        for (auto c = 0; c <= m; c++)
        {
            for (auto r = 0; r < n; r++)
            {
                if (c == m || board[r][c] == '#')
                {
                    if (cnt[r] == len)
                    {
                        auto start = c - len;
                        auto pos = 0;
                        auto matched = true;

                        while (start < c && matched)
                        {
                            if (board[r][start] == ' ')
                            {
                                start++;
                                pos++;
                            }
                            else
                            {
                                if (board[r][start] == word[pos])
                                {
                                    start++;
                                    pos++;
                                }
                                else
                                {
                                    matched = false;
                                }
                            }
                        }

                        if (matched)
                        {
                            return true;
                        }
                    }

                    cnt[r] = 0;
                }
                else
                {
                    cnt[r]++;
                }
            }
        }

        return false;
    }
};