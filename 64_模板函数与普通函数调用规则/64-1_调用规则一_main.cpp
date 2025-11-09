/*
    调用函数时，发现匹配到模板函数(类型严格匹配)的同时，也匹配到普通函数(类型严格匹配)，那么优先调用普通函数
*/
#include <iostream>

template<class T>
T myPrint(T a, T b)
{
    std::cout << "模板函数 调用..." << std::endl;
    return a + b;
}

int myPrint(int a, int b)
{
    std::cout << "普通函数 调用..." << std::endl;
    return a + b;
}

void test01()
{
    std::cout << __FUNCSIG__ << std::endl;
    std::cout << myPrint(1, 2);
}

// 只要有 <> ，就表示 强制使用 函数模板
void test02()
{
    std::cout << __FUNCSIG__ << std::endl;

    std::cout << "强制使用 函数模板" << std::endl;
    std::cout << myPrint<>(1, 2);  // 使用空模板参数列表强制匹配 函数模板
}

int main1(void)
{
    test01();
    std::cout << std::endl << std::endl;
    test02();
    return 0;
}

/*

void __cdecl test01(void)
普通函数 调用...
3

void __cdecl test02(void)
强制使用 函数模板
模板函数 调用...
3

*/