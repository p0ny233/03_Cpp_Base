#include <iostream>

class BaseA
{
public:
    int age;
    BaseA(int a)
    {
        this->age = a;
        std::cout << "BaseA(int a) 有参构造函数" << std::endl;
    }
};

class Sun1 : public BaseA
{
public:
    Sun1(int a=1000) : BaseA(a)  // 由于 父类BaseA 没有默认构造，那么利用初始化列表语法 显式调用父类的有参构造
    {
        std::cout << "Sun1(int a) 有参构造函数" << std::endl;
    }
};

void test01()
{
    Sun1 s1(100);
    std::cout << "s1.age: " << s1.age << std::endl;
}

void test02()
{
    Sun1 s2;
    std::cout << "s2.age: " << s2.age << std::endl;

}

int main(void)
{
    test01();
    std::cout << std::endl;
    test02();
    return 0;
}
/*

BaseA(int a) 有参构造函数
Sun1(int a) 有参构造函数
s1.age: 100

BaseA(int a) 有参构造函数
Sun1(int a) 有参构造函数
s2.age: 1000

*/