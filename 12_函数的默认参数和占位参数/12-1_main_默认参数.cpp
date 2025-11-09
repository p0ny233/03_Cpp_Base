// C没有，在C++才有
#include <iostream>

// 默认参数
int func(int a = 10, int b = 10)
{
    return a + b;
}

void test01()
{
    int ret = func();
    std::cout << "ret: " << ret << std::endl;  // 20
    
    ret = func(20);
    std::cout << "ret: " << ret << std::endl;  // 30

}

// 默认值参数注意事项：如果有一个位置有了默认值，那么从这个位置起，从左到右都必须要要有默认值
//int func2(int a, int b=20, int c) {}  // 编译报错，需要设置第三个参数的默认值


void func3(int a, int b = 3, int c = 2){ }
void test03()
{
    func3(1);
}



// 函数的声明和函数实现只能有一个提供默认值参数，不可以同时提供默认值参数
void func4(int a=10, int b=20);
//void func4(int a = 10, int b = 20)
void func4(int a, int b)
{
    std::cout << a << ", " << b << std::endl;;
}

int main1(void)
{
    test01();
    test03();
    func4(1,2);
    return 0;
}