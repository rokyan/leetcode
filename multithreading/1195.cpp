// https://leetcode.com/problems/fizz-buzz-multithreaded/description/

class FizzBuzz
{
private:
    int n;
    int i = 1;
    std::mutex mutex;
    std::condition_variable cv;

public:
    FizzBuzz(int n)
    {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        for (;;)
        {
            std::unique_lock lock(mutex);
            cv.wait(lock, [this]() { return i > n || i % 3 == 0 && i % 5 != 0; });

            if (i > n)
            {
                return;
            }

            printFizz();
            i++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        for (;;)
        {
            std::unique_lock lock(mutex);
            cv.wait(lock, [this]() { return i > n || i % 3 != 0 && i % 5 == 0; });

            if (i > n)
            {
                return;
            }

            printBuzz();
            i++;
            cv.notify_all();
        }      
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz)
    {
        for (;;)
        {
            std::unique_lock lock(mutex);
            cv.wait(lock, [this]() { return i > n || i % 3 == 0 && i % 5 == 0; });

            if (i > n)
            {
                return;
            }

            printFizzBuzz();
            i++;
            cv.notify_all();
        }         
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        for (;;)
        {
            std::unique_lock lock(mutex);
            cv.wait(lock, [this]() { return i > n || i % 3 != 0 && i % 5 != 0; });

            if (i > n)
            {
                return;
            }

            printNumber(i);
            i++;
            cv.notify_all();
        }          
    }
};