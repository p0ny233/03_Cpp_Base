#include <iostream>

/*
    函数重载的条件

        1. 在同个作用域
        2. 函数名称相同
        3. 函数参数个数不同、类型不同、顺序不同

返回值不可以作为函数重载的条件

*/


// 1 函数参数个数不同
void func1(int a)
{

}
void func1(int a, int b)
{

}
// 2 函数参数类型不同
void func2(int a)
{

}
void func2(double a)
{

}

// 3 函数参数顺序不同
void func3(int a, double b)
{

}
void func3(double a, int b)
{

}

//int func3(double a, int b)  // 返回值不可以作为 重载的条件
//{
//
//}


int main1(void)
{
    return 0;
}