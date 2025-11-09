#include <iostream>

void func(int& a)
{
    std::cout << "func(int& a)" << std::endl;

}

void func(const int& b)
{
    std::cout << "func(const int& b)" << std::endl;
}

void test()
{
    func(1);  // func(const int& b)
    
    int a = 12;
    func(a);  // func(int& a)
}

int main(void)
{
    test();
    return 0;
}