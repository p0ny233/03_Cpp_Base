#include <iostream>

class BaseA
{
public:
    // 成员属性同名
    int m_A;
    BaseA()
    {
        m_A = 10;
    }
    // 成员函数同名
    void func01()
    {
        std::cout << "BaseA::func01() 调用" << std::endl;

    }
};

class Sub00 : public BaseA
{
public:
    Sub00()
    {
        m_A = 20;
    }
};

class Sub01 : public BaseA
{
public:
    int m_A;
    Sub01()
    {
        m_A = 20;
    }
    // 成员函数同名
    void func01()
    {
        std::cout << "Sub01::func01() 调用" << std::endl;

    }
};




// 优先查 子类的成员，子类中没有该成员 再查 父类成员
void test00()
{
    Sub00 s0;
    std::cout << "s0.m_A: " << s0.m_A << std::endl;
    // s0.m_A: 20
}

// 属性同名时，优先访问子类的属性
void test01()
{
    Sub01 s1;
    std::cout << "s1.m_A: " << s1.m_A << std::endl;
    // s1.m_A: 20

}


// 属性同名时，若是要访问父类的属性，则利用作用域运算符 通过子类 访问父类中的 m_A成员属性
void test02()
{
    Sub01 s2;
    std::cout << "子类的 s2.m_A: " << s2.m_A << std::endl;
    std::cout << "父类的 s2.m_A: " << s2.BaseA::m_A << std::endl;

/*
子类的 s2.m_A: 20
父类的 s2.m_A: 10
*/
}

// 函数同名时，优先访问 子类中的成员函数
void test03()
{
    Sub01 s3;
    s3.func01();

// Sub01::func01() 调用
}


// 函数同名时，若是要访问父类的函数，则利用作用域运算符 通过子类 访问父类中的 成员函数
void test04()
{
    Sub01 s4;
    s4.BaseA::func01();

// BaseA::func01() 调用
}

int main(void)
{

    test00();
    std::cout << std::endl;
    test01();
    std::cout << std::endl;
    test02();
    std::cout << std::endl;
    test03();
    std::cout << std::endl;
    test04();
    return 0;
}
/*

s0.m_A: 20

s1.m_A: 20

子类的 s2.m_A: 20
父类的 s2.m_A: 10

Sub01::func01() 调用

BaseA::func01() 调用

*/