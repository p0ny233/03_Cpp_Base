#include <iostream>

class BaseA
{
public:

    static void func()
    {
        std::cout << "BaseA::func() 调用" << std::endl;
    }
    static void func(int a)
    {
        std::cout << "BaseA::func(int a) 调用" << std::endl;
    }
};

class Sun01 : public BaseA
{
public:
    static void func()
    {
        std::cout << "Sun01::func() 调用" << std::endl;
    }
};

void test01()
{
    Sun01 s1;
    s1.func();

    //s1.func(2);  // 无法调用 父类的func有参版本。子类重写了父类版本的func函数，导致屏蔽掉父类所有的重载版本。

    //  利用作用域运算符 显式调用 父类func
    s1.BaseA::func();
    Sun01::BaseA::func();

/*

Sun01::func() 调用
BaseA::func() 调用
BaseA::func() 调用

*/
}


int main(void)
{
    test01();

    return 0;
}