// https://leetcode.com/problems/print-foobar-alternately/description/

class FooBar
{
private:
    int n;

public:
    FooBar(int n)
    {
        this->n = n;
    }

    void foo(function<void()> printFoo)
    {
        for (int i = 0; i < n; i++)
        {
            foobs.acquire();
            printFoo();
            barbs.release();
        }
    }

    void bar(function<void()> printBar)
    {
        for (int i = 0; i < n; i++)
        {
            barbs.acquire();
            printBar();
            foobs.release();
        }
    }

private:
    std::binary_semaphore foobs{1};
    std::binary_semaphore barbs{0};
};