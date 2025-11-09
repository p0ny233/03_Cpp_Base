#include <iostream>

class Person
{

};

void test01()
{
    Person p1;
    std::cout << "sizeof(p1): " << sizeof(p1) << std::endl;
}


class Animal
{
    // 只有 成员变量 属于类对象
    int m_A;  // 占 4 字节
    
    // 成员函数，不属于类对象
    void func()
    {
        std::cout << __func__ << std::endl;
    }
    // 静态成员函数，不属于类对象
    static void func2()
    {
        std::cout << __func__ << std::endl;
    }
};

void test02()
{
    Animal a1;
    std::cout << "sizeof(a1): " << sizeof(a1) << std::endl;

}

int main(void)
{
    test01();
    test02();

    return 0;
}

/*

sizeof(p1): 1
sizeof(a1): 4

*/