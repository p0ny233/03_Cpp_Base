#include <iostream>

class MyOutOfRangeException : public std::exception
{
std::string mMessage;
public:
    MyOutOfRangeException(const char* msg)
    {
        mMessage = msg;
    }
    // 重写父类虚函数
    virtual char const* what() const
    {
        return mMessage.c_str();
    }
};

class Person
{
    int mAge;
public:
    Person(int age)
    {
        if(age < 0 || age > 150)
        {
            throw MyOutOfRangeException("年龄要在 0~150之间");
        }
        this->mAge = age;
    }
};

void test01()
{
    try
    {
        Person(151);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    test01();
    return 0;
}