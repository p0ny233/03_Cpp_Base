#include <iostream>


// 告诉编译器， T代表这是个通用类型，
// 告诉编译器下面紧跟着的函数或者类中 使用了 T，不要报错
template <typename T>
void SwapValue(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}


void test01()
{
    int a = 1;
    int b = 2;
    char c1 = '3';
    char c2 = '4';
    double d1 = 3.14;
    double d2 = 5.22;
    std::cout << "使用 函数模板技术 - 编译器自动类型推导" << std::endl;

    // 1. 调用函数模板的方式一：由编译器自动类型推导
    SwapValue(a, b);
    SwapValue(c1, c2);
    SwapValue(d1, d2);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "d1 = " << d1 << std::endl;
    std::cout << "d2 = " << d2 << std::endl;
}


void test02()
{
    int a = 1;
    int b = 2;
    char c1 = '3';
    char c2 = '4';
    double d1 = 3.14;
    double d2 = 5.22;
    std::cout << "使用 函数模板技术 - 显式指定类型" << std::endl;

    // 2. 调用函数模板的方式二：显式指定类型 
    //     (允许隐式类型转换，但函数模板形参指定为引用时，调用时必须同类型左值，不允许类型转换)
    SwapValue<int>(a, b);
    SwapValue<char>(c1, c2);
    SwapValue<double>(d1, d2);
    //SwapValue<double>(a, b);  // 由于指定形参为引用类型，不允许隐式类型转换

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "d1 = " << d1 << std::endl;
    std::cout << "d2 = " << d2 << std::endl;

}

int main(void)
{
    test01();
    std::cout << std::endl;
    test02();

    return 0;
}
/*

使用 函数模板技术 - 编译器自动类型推导
a = 2
b = 1
c1 = 4
c2 = 3
d1 = 5.22
d2 = 3.14

使用 函数模板技术 - 显式指定类型
a = 2
b = 1
c1 = 4
c2 = 3
d1 = 5.22
d2 = 3.14

*/