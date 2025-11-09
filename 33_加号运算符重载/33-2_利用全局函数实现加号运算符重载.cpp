/*
    利用全局函数实现加号运算符重载
*/
#include <iostream>

class Person
{
public:
    int mA;
    int mB;

    Person():mA(0), mB(0){}
    Person(int a, int b): mA(a), mB(b){}
};

Person operator+(const Person& p1, const Person& p2)
{
    std::cout << "全局函数 实现加号运算符 重载" << std::endl;
    Person tmp;
    tmp.mA = p1.mA + p2.mA;
    tmp.mB = p1.mB + p2.mB;
    return tmp;   
}

void test02()
{
    Person p1(10, 10);
    Person p2(20, 20);

    Person p3 = p1 + p2;  // 简化写法
    
    // 本质写法：
    Person p4 = operator+(p1, p2);
    std::cout << "p3 " << p3.mA << ", " << p3.mB << std::endl;
    std::cout << "p4 " << p4.mA << ", " << p4.mB << std::endl;
}

int main1(void)
{

    test02();
    return 0;
}
/*

全局函数 实现加号运算符 重载
全局函数 实现加号运算符 重载
p3 30, 30
p4 30, 30

*/