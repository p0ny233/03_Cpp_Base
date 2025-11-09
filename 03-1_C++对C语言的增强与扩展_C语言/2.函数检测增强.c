// 函数检测增强，返回值类型检测，形参类型检测，函数调用个数检测
#include <stdio.h>

getRect(w, h)  // 在C语言中没有对函数返回值类型，形参类型等检测。可以编译通过
{
    return w * h;
}

//int main(void)
//{
//    printf("Rect: %d\n", getRect(10, 11, 12));
//    return 0;
//}

/*

Rect: 110

*/

