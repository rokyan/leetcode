class ZeroEvenOdd
{
private:
    int n;
    std::binary_semaphore zeroSem{1};
    std::binary_semaphore evenSem{0};
    std::binary_semaphore oddSem{0};

public:
    ZeroEvenOdd(int n)
        : n{n}
    {}

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i++)
        {
            zeroSem.acquire();
            printNumber(0);

            if (i % 2 == 1)
            {
                oddSem.release();
            }
            else
            {
                evenSem.release();
            }          
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            evenSem.acquire();
            printNumber(i);
            zeroSem.release();
        }
    }

    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2)
        {
            oddSem.acquire();
            printNumber(i);
            zeroSem.release();
        }
    }
};