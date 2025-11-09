#include <iostream>

class Person
{
    int mAge;
public:
    Person(int age)
    {
        if(age < 0 || age > 150)
        {
            throw std::out_of_range("年龄必须在 0~150之间");
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
    //catch(std::out_of_range &e)  // 异常子类
    //{
    //    std::cout << e.what() << std::endl;;
    //}
    catch(std::exception &e)  // 异常的基类
    {
        std::cout << e.what() << std::endl;;
    }
}

int main(void)
{
    test01();
    return 0;
}