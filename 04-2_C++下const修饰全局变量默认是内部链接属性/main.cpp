#include <iostream>

int main(void)
{

    extern const int g_cpp_1;  // c++中，const修饰的全局变量是内部链接，因此链接失败
    extern const int g_cpp_2;  // 访问其他文件中的const全局变量，且该变量使用 extern修饰，因此可以被外部访问，编译通过


    //std::cout << g_cpp_1 << std::endl;  // fatal error LNK1120: 1 个无法解析的外部命令
    std::cout << g_cpp_2 << std::endl;  // 该变量使用 extern修饰，因此可以被外部访问，编译通过
    return 0;
}