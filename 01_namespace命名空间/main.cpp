/*
    1. 命名空间解决命名冲突问题

    2. 命名空间下可以放变量、函数、结构体、类等

    3. 命名空间必须要声明在全局作用域下

    4. 命名空间可以嵌套命名空间

    5. 命名空间是开放的，可以随时给命名空间添加新的成员

    6. 命名空间可以是匿名的

    7. 命名空间可以起别名

*/

#include <iostream>
#include "game1.h"
#include "game2.h"

void test01()  // 1. 命名空间解决命名冲突问题
{
    LOL::goAck();
    KingGroly::goAck();
}

// 2. 命名空间下可以放变量、函数、结构体、类等
namespace ROM_A
{
    int m_a = 0;

    void fun()
    {
        std::cout << "ROM_A::fun" << std::endl;
    }

    struct Person
    {
        int age;
        char name[64];
    };
    
    class Desk
    {
        int width;
        int height;
    };
}

// 3. 命名空间必须要声明在全局作用域下，如下为错误示例
//void test()
//{
//    namespace ROM_TEST  // 语法错误
//    {
//
//    }
//}

// 4. 命名空间可以嵌套命名空间
namespace ROM_B
{
    int var = 0;

    namespace ROM_C
    {
        int var = 0;
    }
}

// 测试: 命名空间可以嵌套命名空间
void test02()
{
    std::cout << "ROM_B::var: " << ROM_B::var << std::endl;
    std::cout << "ROM_B::ROM_C::var: " << ROM_B::ROM_C::var << std::endl;
}


// 5. 命名空间是开放的，可以随时给命名空间添加新的成员
namespace ROM_B
{
    int var_2 = 123;
}

// 测试：命名空间可以随时给命名空间添加新的成员
void test03()
{
    std::cout << "ROM_B空间下的 var_2： " << ROM_B::var_2 << std::endl;
}




// 6. 命名空间可以是匿名的
namespace  // 相当于是全局作用域
{
    int m_d = 1000;
    int m_c = 2000;

    // 以上两行代码相当于 如下代码：
    // static int m_d = 1000;
    // static int m_c = 2000;
}

// 测试: 命名空间可以是匿名的
void test04()
{
    std::cout << "匿名空间下的 m_d: " << m_d << std::endl;
    std::cout << "匿名空间下的 m_c: " << ::m_c << std::endl;
}

// 7. 命名空间可以起别名
namespace LongName
{
    int m_e = 333;
}

void test05()
{
    // 给命名空间起别名
    namespace shortName = LongName;
    std::cout << "shortName下的 m_e: " << shortName::m_e << std::endl;
}

int main(void)
{
    test01();

    std::cout << std::endl;
    test02();

    std::cout << std::endl;
    test03();

    std::cout << std::endl;
    test04();

    std::cout << std::endl;
    test05();

    return 0;
}

/*

LOL::goAck
KingGroly::goAck

ROM_B::var: 0
ROM_B::ROM_C::var: 0

ROM_B空间下的 var_2： 123

匿名空间下的 m_d: 1000
匿名空间下的 m_c: 2000

shortName下的 m_e: 333

*/