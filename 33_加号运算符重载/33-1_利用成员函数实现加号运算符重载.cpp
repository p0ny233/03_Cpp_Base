/*
    利用成员函数实现加号运算符重载
*/
#include <iostream>

class Person
{
public:

    int mA;
    int mB;
    Person():mA(0), mB(0){};
    Person(int a, int b): mA(a), mB(b){}

    // 利用成员函数 实现加号运算符重载
    Person operator+(Person& ref);
};

// 利用成员函数 实现加号运算符重载
Person Person::operator+(Person& ref)
{

    std::cout << "成员函数 实现加号运算符 重载" << std::endl;

    Person tmp;

    tmp.mA = this->mA + ref.mA;
    tmp.mB = this->mB + ref.mB;
    return tmp;
}

void test01()
{
    Person p1(10, 10);
    Person p2(20, 20);
    // 调用方式一（本质写法）
    Person p3 = p1.operator+(p2);
    
    // 调用方式二（简化写法）
    Person p4 = p1 + p2;

    std::cout << "p3的值为：" << p3.mA << ", " << p3.mB << std::endl;
    std::cout << "p4的值为：" << p4.mA << ", " << p4.mB << std::endl;
}

int main(void)
{
    test01();
    return 0;
}

/*

成员函数 实现加号运算符 重载
成员函数 实现加号运算符 重载
p3的值为：30, 30
p4的值为：30, 30

*/