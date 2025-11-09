#include <iostream>

// 1. 提供了有参构造函数，编译器不会提供默认构造函数，但依然会提供拷贝构造函数
class Person01
{
public:
    int mAge;
    Person01(int age)  // 有参构造
    {
        mAge = age;
    }
};

void test01()
{
    Person01 p1(10);
    Person01 p2(p1);  // 说明即使提供了有参构造函数，编译器依然提供 拷贝构造函数
    std::cout << "p2的年龄: " << p2.mAge << std::endl;
    
}

// 2. 如果提供了拷贝构造函数，编译器不会提供其他的任何构造函数
class Person02
{
public:
    int mAge;
    Person02(const Person02& ref)  // 拷贝构造
    {
        mAge = ref.mAge;
    }
};

void test02()
{
    //Person02 p2;  // 语法错误，不存在默认构造，说明提供了拷贝构造函数后，编译器不会提供其他的构造函数
    
}

int main(void)
{
    test01();
    return 0;
}