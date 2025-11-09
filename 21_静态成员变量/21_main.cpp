#include <iostream>

class Person
{
public:
    static int m_A;  // 类内声明
};

// 类外初始化（不需要加 static关键字 ）
int Person::m_A = 0;

// 所有Person对象共享同一份数据
void test01()
{
    Person p1;
    std::cout << "p1对象的 m_A值: " << p1.m_A << std::endl;

    Person p2;
    p2.m_A = 111;  // 可以通过其他对象 修改静态成员变量
    std::cout << "p1对象的 m_A值: " << p1.m_A << std::endl;

}

void test02()
{
    Person p;
    std::cout << "通过对象访问 静态成员变量: " << p.m_A << std::endl;
    std::cout << "通过类名访问 静态成员变量: " << Person::m_A << std::endl;
}

int main(void)
{
    test01();
    test02();
    return 0;
}

/*

p1对象的 m_A值: 0
p1对象的 m_A值: 111
通过对象访问 静态成员变量: 111
通过类名访问 静态成员变量: 111

*/