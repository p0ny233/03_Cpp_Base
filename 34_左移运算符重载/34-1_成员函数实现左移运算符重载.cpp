/*

1. 对于自定义数据类型，不可以直接用 `cout <<` 输出
2. 需要重载左移运算符时，应选择**全局函数**来实现左移运算符重载，原因是成员函数实现左移运算符无法让`cout`在左侧，因此不用成员函数重载
    ```cpp
    ostream& operator<<(ostream& out, Person& p);
    ```
3. 如果要访问类中的私有属性，可以配置友元函数来实现

*/

#include <iostream>

class Person
{
    friend std::ostream& operator<<(std::ostream& out, Person& p);

    int mA;
    int mB;
public:
    Person(): mA(0), mB(0){}
    Person(int a, int b): mA(a), mB(b){}
};

std::ostream& operator<<(std::ostream& out, Person& p)
{
    // 设置成 友元函数，实现该函数可以访问 Person的私有属性
    out << "p.mA: " << p.mA << ", p.mB: " << p.mB;
    return out;
}

void test01()
{
    Person p1(10, 10);
    std::cout << p1 << std::endl;
}

int main(void)
{
    test01();
    return 0;
}

// p.mA: 10, p.mB: 10
