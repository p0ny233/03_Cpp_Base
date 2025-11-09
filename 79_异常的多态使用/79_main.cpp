#include <iostream>

class BaseException
{
public:
    virtual void printError() = 0;
};

// 空指针异常
class NullPointException : public BaseException
{
public:
    void printError()
    {
        std::cout << "空指针异常" << std::endl;
    }
};

// 越界异常
class OutOfRangeException : public BaseException
{
public:
    void printError()
    {
        std::cout << "越界异常" << std::endl;
    }
};

void dowork()
{
    //throw NullPointException();
    throw OutOfRangeException();
}

void test01()
{
    try {
        dowork();
    }
    catch(BaseException& e)
    {
        e.printError();
    }
}

int main(void)
{
    test01();
    return 0;
}