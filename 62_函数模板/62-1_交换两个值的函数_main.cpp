#include <iostream>

void SwapInt(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void SwapDouble(double& a, double& b)
{
    double tmp = a;
    a = b;
    b = tmp;
}

void SwapChar(char& a, char& b)
{
    char tmp = a;
    a = b;
    b = tmp;
}


int main1(void)
{
    int a = 1;
    int b = 2;
    char c1 = '3';
    char c2 = '4';
    double d1 = 3.14;
    double d2 = 5.22;
    
    SwapInt(a, b);
    SwapChar(c1, c2);
    SwapDouble(d1, d2);
    
    std::cout << "a = "  << a  << std::endl;
    std::cout << "b = "  << b  << std::endl;
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "d1 = " << d1 << std::endl;
    std::cout << "d2 = " << d2 << std::endl;

    return 0;
}

/*

    各个交换两个值的函数逻辑是类似的，也就是一个逻辑要实现多次
        使用函数模板可以避免这种情况

*/