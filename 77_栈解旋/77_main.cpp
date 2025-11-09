#include <iostream>
class Person
{
public:
    Person()
    {
        std::cout << "Person 构造" << std::endl;
    }
    ~Person()
    {
        std::cout << "Person 析构" << std::endl;
    }
};

class myException
{
public:
    myException()
    {
        std::cout << "myException 构造" << std::endl;
    }

    ~myException()
    {
        std::cout << "myException 析构" << std::endl;

    }
};

void computer()
{

    Person p1;

    throw myException();
}

void test01()
{
    try
    {
        computer();
    }
    catch(...)
    {

    }
    std::cout << "test01 end" << std::endl;

}

int main(void)
{
    test01();
    std::cout << "main end" << std::endl;
    return 0;
}
/*

Person 构造
myException 构造
Person 析构
myException 析构
test01 end
main end

*/