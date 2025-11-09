#include <iostream>

class MyPrint
{
public:
    void operator()(std::string text)
    {
        std::cout << text << std::endl;
    }
};

class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

void test01()
{
    MyPrint mp;
    mp("Hello");
}

// 仿函数（函数对象），把对象当作函数调用，
void test02()
{
    MyAdd myadd;
    std::cout << "常规调用方式: " << myadd(1, 2) << std::endl;
    std::cout << "创建匿名对象后调用: " << MyAdd()(1, 2) << std::endl;
}


int main(void)
{

    test01();
    test02();

    return 0;
}
/*

Hello
常规调用方式: 3
创建匿名对象后调用: 3

*/