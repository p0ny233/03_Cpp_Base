/*
    1. 值传递
    2. 地址传递
    3. 引用传递
*/

#include <iostream>

// 1. 值传递
void mySwap01(int a, int b)
{
    int temp = b;
    a = b;
    b = temp;
}
void test01()
{
    int a = 11;
    int b = 22;
    mySwap01(a, b);  // 值传递
    std::cout << __func__ << ", a = " << a << std::endl;  // 11
    std::cout << __func__ << ", b = " << b << std::endl;  // 22
}

// 2. 地址传递
void mySwap02(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void test02()
{
    int a = 11;
    int b = 22;
    mySwap02(&a, &b);  // 地址传递
    std::cout << __func__ << ", a = " << a << std::endl;  // 22
    std::cout << __func__ << ", b = " << b << std::endl;  // 11
}


// 3. 引用传递
void mySwap03(int& a, int& b)
{
    int temp = b;
    b = a;
    a = temp;
}

void test03()
{
    int a = 11;
    int b = 22;
    mySwap02(&a, &b);  // 引用传递
    std::cout << __func__ << ", a = " << a << std::endl;  // 22
    std::cout << __func__ << ", b = " << b << std::endl;  // 11
}


int main(void)
{
    test01();
    test02();
    test03();
    return 0;
}
/*
test01, a = 11
test01, b = 22
test02, a = 22
test02, b = 11
test03, a = 22
test03, b = 11
*/