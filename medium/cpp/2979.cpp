// https://leetcode.com/problems/most-expensive-item-that-can-not-be-bought/submissions/

class Solution
{
public:
    int mostExpensiveItem(int primeOne, int primeTwo)
    {
        return primeOne * primeTwo - primeOne - primeTwo;
    }
};