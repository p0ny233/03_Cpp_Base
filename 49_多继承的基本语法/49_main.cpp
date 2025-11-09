#include <iostream>

class BaseA
{
public:
    int m_A;
    BaseA()
    {
        m_A = 1;
    }
};

class BaseB
{
public:
    int m_A;
    BaseB()
    {
        m_A = 2;
    }
};

class Sub : public BaseA, public BaseB
{
public:
    int m_B;
};

void test01()
{
    Sub s;
    std::cout << "sizeof(s): " << sizeof(s) << std::endl;  // sizeof(s): 12
}

// 两个父类中，同名的成员如何访问，只能通过 作用域 指定访问哪个父类
void test02()
{
    Sub s;
    //std::cout << s.m_A << std::endl;  // error, BaseA和BaseB都有 m_A，具体访问哪个不确定
    
    // 需要通过作用域运算符指定
    std::cout << "s.BaseA::m_A: " << s.BaseA::m_A << std::endl;
    std::cout << "s.BaseB::m_A: " << s.BaseB::m_A << std::endl;
    
}

int main(void)
{
    test01();
    std::cout << std::endl;
    test02();
    return 0;
}
/*

sizeof(s): 12

s.BaseA::m_A: 1
s.BaseB::m_A: 2

*/