#include <iostream>

class Person
{
public:
    Person(){}
    
    int age;
    
    static void func()
    {
        //age = 100;  // 在静态函数中， 不能访问 对象变量
        std::cout << __func__ << std::endl;
    }
};

void test01()
{
    // 访问方式一：通过对象访问
    Person p1;
    p1.func();
    
    // 访问方式二：通过类名访问
    Person::func();
}

int main(void)
{
    test01();
    return 0;
}