/*
    1. 引用必须引用一块合法的内存空间
    2. 不要返回局部变量的引用

*/
#include <iostream>

// 1. 引用必须引用一块合法的内存空间
void test01()
{
    //int &a = 10; // 语法错误
}

// 2. 不要返回局部变量的引用
int& test02()
{
    int a = 11;
    return a;
}

int& test03()
{
    static int var = 1111;
    return var;
}
int main(void)
{
    int& ref = test02();
    std::cout << "ref: " << ref << std::endl;  // 访问无意义的值

    
    int &ref2 = test03();
    std::cout << "ref2: " << ref2 << std::endl;
    
    // 当函数返回值 返回引用，引用可以作为左值
    test03() = 9999;  
    std::cout << "ref2: " << ref2 << std::endl;
    return 0;
}

/*
ref: -858993460
ref2: 1111
ref2: 9999
*/