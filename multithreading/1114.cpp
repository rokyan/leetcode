// https://leetcode.com/problems/print-in-order/description/

class Foo
{
public:
    Foo() = default;

    void first(function<void()> printFirst)
    {
        {
            std::lock_guard lock(mutex);
            printFirst();
            state = 1;
        }

        cv1.notify_one();
    }

    void second(function<void()> printSecond)
    {
        {
            std::unique_lock lock(mutex);
            cv1.wait(lock, [this]() { return state == 1; });
            printSecond();
            state = 2;
        }

        cv2.notify_one();
    }

    void third(function<void()> printThird)
    {
        std::unique_lock lock(mutex);
        cv2.wait(lock, [this]() { return state == 2; });
        printThird();
    }

private:
    std::condition_variable cv1;
    std::condition_variable cv2;
    std::mutex mutex;
    int state = 0;
};