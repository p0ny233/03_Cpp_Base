/*
    1. 全局变量检测增强，C++会出现重定义
*/
#include <stdio.h>

int redefine;
int redefine = 22;  // 在C语言中 编译通过
