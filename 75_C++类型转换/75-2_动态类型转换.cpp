#include <iostream>

class Base{};
class Son : public Base{};

class Animal02 { virtual void func(){} };
class Cat02 : public Animal02 { void func() {} };

void test02()
{
    // 1. 不允许内置类型转换
    char c = 'c';
    //double d = dynamic_cast<char>(c);  // error

    // 2. 允许父子之间指针或引用的转换
    // 2.1 父转子，不安全，转换失败，但如果子类重写父类的虚函数，那么就可以转换成功
    Base* base = new Base;
    //Son* s = dynamic_cast<Son*>(base);  // error，没有重写虚函数，转换失败。
    
    // 父转子，不安全，子类对父类的虚函数重写，可以转换成功
    Animal02 *ani2 = new Animal02;
    Cat02 *cat1 = dynamic_cast<Cat02*>(ani2);  // 重写虚函数，发生多态，因此转换成功
    
    // 2.2 子转父，安全，转换成功
    Son* son = nullptr;
    Base* b2 = dynamic_cast<Base*>(son);


}
int main2(void)
{
    test02();
    return 0;
}