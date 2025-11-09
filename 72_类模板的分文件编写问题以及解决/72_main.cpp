//#include "person.h"  // error
/*
    模板声明写在 person.h
    模板实现写在 person.cpp
在链接阶段发生报错

    应该把模板的声明和实现写在一块 person.hpp 文件
*/

#include "person.hpp"
#include <iostream>

//void test01()
//{
//    Person<int> p1;
//}

void test02()
{
    Person02<std::string, int> p2;
    p2.showPerson();
}

int main(void)
{
    test02();
    return 0;
}