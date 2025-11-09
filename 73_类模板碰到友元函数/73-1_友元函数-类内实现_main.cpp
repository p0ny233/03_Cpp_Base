#include <iostream>

template<class T1, class T2>
class Person01
{
    // 友元函数，类内实现
    friend void printPerson1(Person01<T1, T2> &ref)
    {
        std::cout << "类内实现 友元函数" << std::endl;
        std::cout << "姓名: " << ref.mName << ", 年龄: " << ref.mAge << std::endl;
    }

    T1 mName;
    T2 mAge;
public:
    Person01(T1 name, T2 age)
    {
        this->mName = name;
        this->mAge = age;
    }
};

void test01()
{
    Person01<std::string, int> p1("tom", 11);
    printPerson1(p1);
}

int main1(void)
{
    test01();
    return 0;
}
/*

类内实现 友元函数
姓名: tom, 年龄: 11

*/