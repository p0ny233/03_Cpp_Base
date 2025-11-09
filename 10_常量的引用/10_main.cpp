#include <iostream>

void test01()
{
    //int& ref = 10;  // 语法错误
    const int& refa = 20;
    int* p = (int*) & refa;
    *p = 33;
    std::cout << "refa: " << refa << std::endl;

}

int getValue(const int& val)  // 常量的引用应用场景：修饰函数中的形参，防止误操作
{
    //val = 22;  // 被const修饰，无法修改
    return val;
}

void test02()
{
    int a = 12;
    int ret = getValue(a);
    std::cout << "ret: " << ret << std::endl;
}

int main(void)
{
    test01();
    test02();
    return 0;
}

/*

refa: 33
ret: 12

*/