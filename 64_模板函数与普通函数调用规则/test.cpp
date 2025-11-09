#include <iostream>

template<class T>
void func(T a, T b)
{
    std::cout << "函数模板 1" <<std::endl;
}

void func(int a, int b)
{
    std::cout << "普通函数 2" << std::endl;
}


int main(void)
{
    func(1, 2);       // 普通函数，自动类型推导(不允许隐式类型转换)，都不需要类型转换的情况下，依旧调用 普通函数
    func<int>(1, 2);  // 模板函数，显式指定调用，已经明确使用 <int>语法，那么 会直接匹配 函数模板
    func('a', 1);     // 自动推导不允许隐式类型转换，就会产生两种类型，就不匹配，那么只能是调用 普通函数
    func('c', 'd');   // 参数类型只有一种就是 char，而普通函数的形参类型需要隐式转换，因此优先 使用 函数模板
    return 0;
}
/*

普通函数 2
函数模板 1
普通函数 2
函数模板 1

*/