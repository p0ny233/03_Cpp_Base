#include <iostream>
class Animal01 {};

class Cat : public Animal01{ };

void test01()
{
    // 1. 内置数据类型转换
    char c = 'a';
    double d = static_cast<double>(c);
    std::cout << d << std::endl;  // 97

    // 2. 允许父子之间的指针或引用的转换
    // 指针
    Cat* cat = nullptr;
    Animal01* ani = cat;                 // 子转父
    Cat* ani2 = static_cast<Cat*>(ani);  // 父转子

    // 引用
    Cat& ref = *(new Cat);
    Animal01 &refa = ref;                // 子转父
    Cat &refb = static_cast<Cat&>(refa); // 父转子
    
}
int main1(void)
{
    test01();
    return 0;
}