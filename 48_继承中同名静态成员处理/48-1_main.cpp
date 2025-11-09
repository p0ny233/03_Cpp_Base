#include <iostream>

class BaseA
{
public:
    // 静态变量 类内声明
    static int m_A; 
    static void func()
    {
        std::cout << "BaseA::func() 调用" << std::endl;
    }
};

// 静态变量 类外定义
int BaseA::m_A = 10;


class Sub01 : public BaseA
{
public:
    static int m_A;
    static void func()
    {
        std::cout << "Sub01::func() 调用" << std::endl;
    }
};
// 静态变量 类外定义
int Sub01::m_A = 20;

// 访问静态成员变量
void test01()
{
    Sub01 s1;
    // 1. 通过对象名访问 同名静态成员变量
    std::cout << s1.m_A << std::endl;  // 20 ， 优先访问子类的静态成员变量，和 非静态成员变量的访问 结论一样
    // 2. 通过类名访问 同名静态成员变量
    std::cout << "Sub01::m_A: " << Sub01::m_A << std::endl;
    std::cout << "BaseA::m_A: "<< BaseA::m_A << std::endl;
    std::cout << "Sub01::BaseA::m_A: "<< Sub01::BaseA::m_A << std::endl;

/*

20
Sub01::m_A: 20
BaseA::m_A: 10
Sub01::BaseA::m_A: 10

*/
}

// 访问静态成员函数
void test02()
{
    Sub01 s1;
    // 1. 通过对象名访问 同名静态成员函数
    s1.func();
    // 2. 通过类名访问 同名静态成员函数
    Sub01::func();
    BaseA::func();
    Sub01::BaseA::func();

    /*

    Sub01::func() 调用
    Sub01::func() 调用
    BaseA::func() 调用
    BaseA::func() 调用

    */
}

int main(void)
{
    test01();
    std::cout << std::endl;
    test02();

    return 0;
}

/*

20
Sub01::m_A: 20
BaseA::m_A: 10
Sub01::BaseA::m_A: 10

Sub01::func() 调用
Sub01::func() 调用
BaseA::func() 调用
BaseA::func() 调用

*/