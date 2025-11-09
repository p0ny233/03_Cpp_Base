/*
    1. 对普通变量建立引用
    2. 对数组建立引用

引用的本质：《起别名》
*/
#include <iostream>

// 1. 对普通变量建立引用，基本语法：类型名 &别名 = 原始变量名
void test01()
{
    int a = 10;
    int &b = a;  // 建立对变量a 的引用
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl << std::endl;;  // 以引用的方式访问

    //int &c;  //  定义引用c的同时要对引用c进行初始化，否则报错

    // b 已经与 a建立引用，一旦建立后不可以更改
    int d = 200;
    b = d;  // 这行并不是更改引用b 的指向，而是赋值

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "d = " << d << std::endl << std::endl;

}

// 2. 对数组建立引用
void test02()
{
    // 2.1 第一种建立引用的方法：直接建立引用
    int arr[10];
    int(&refArr)[10] = arr;  //  refArr 与 数组arr 建立引用
    for(int i = 0; i < 10; i++)
        arr[i] = 100 + i;

    for(int i = 0; i < 10; i++)
        std::cout << "refArr[" << i << "]: " << refArr[i] << std::endl; // 以引用的方式访问

    std::cout << std::endl;
    // 2.2 第二种建立引用的方法：先定义出数组的类型，再通过类型定义 引用
    typedef int(ARRAY_TYPE)[10];  // 数组的类型
    
    // 通过基本语法建立引用：类型名 &别名 = 原始变量名
    ARRAY_TYPE &refArr2 = arr;  // 建立引用
    for(int i = 0; i < 10; i++)
        std::cout << "refArr2[" << i << "]: " << refArr2[i] << std::endl; // 以引用的方式访问
}

int main(void)
{
    test01();
    test02();

    return 0;
}
/*

a = 10
b = 10

a = 200
b = 200
d = 200

refArr[0]: 100
refArr[1]: 101
refArr[2]: 102
refArr[3]: 103
refArr[4]: 104
refArr[5]: 105
refArr[6]: 106
refArr[7]: 107
refArr[8]: 108
refArr[9]: 109

refArr2[0]: 100
refArr2[1]: 101
refArr2[2]: 102
refArr2[3]: 103
refArr2[4]: 104
refArr2[5]: 105
refArr2[6]: 106
refArr2[7]: 107
refArr2[8]: 108
refArr2[9]: 109

*/