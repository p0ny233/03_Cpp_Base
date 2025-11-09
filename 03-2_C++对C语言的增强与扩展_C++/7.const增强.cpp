#include <iostream>

// 全局const，数据存储在只读数据区，与 C 语言的结论一致
const int g_var = 100;  // 
void test01()
{
    //g_var = 200;  // 编译失败，g_var 内存分配在常量区
    
    int* ptr = (int*) &g_var;  // c++类型检查比较严格，赋值左右两边类型要一致
    //*ptr = 200;  // 运行阶段报错，修改只读数据区的内存会报错
}

// 局部 const
void test02()
{
    const int l_var = 111;
    //l_var = 2;  // 编译失败，编译阶段报错，由编译器进行 语法检查

    // 使用指针间接修改
    int* ptr = (int*)&l_var;
    *ptr = 222;
    std::cout << "l_var     : " << l_var << std::endl;  // 编译阶段从 符号表中查找，相当于常量
    std::cout << "l_var     : " << *ptr << std::endl;   // 以指针方式 访问内存

    int arr[l_var];  // 编译通过，从符号表中查找值，相当于常量
}


int main(void)
{
    test01();
    test02();
    return 0;
}