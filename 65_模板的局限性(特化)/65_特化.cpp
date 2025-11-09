/*
    当遇到 函数模板 遇到 自定义的数据类型
*/
#include <iostream>

class Person
{
public:

    std::string mName;
    int mAge;

    Person(std::string name, int age) : mName(name), mAge(age) {}
};

template<class T>
bool myCompare(T &a, T &b)
{
    return a == b;  //  内置类型正常，但是遇到自定义的数据类型，比较的是 地址，因此需要另外实现自定数据类型比较的逻辑
}

template<> bool myCompare(Person& p1, Person& p2)
{
    if(p1.mName == p2.mName && p1.mAge == p2.mAge)
    {
        std::cout << "p1 == p2" << std::endl;
        return true;
    }
    else
        std::cout << "p1 != p2" << std::endl;
        return false;    
}

void test01()
{
    int a = 1;
    int b = 1;
    std::cout << myCompare(a, b) << std::endl;  // 1
}

// 自定义数据类型
void test02()
{
    Person p1("Tom", 19);
    Person p2("Tom", 19);
    Person p3("111", 20);

    myCompare(p1, p3);  // p1 != p2
    myCompare(p1, p2);  // p1 == p2
}

int main(void)
{

    test01();
    test02();

    return 0;
}