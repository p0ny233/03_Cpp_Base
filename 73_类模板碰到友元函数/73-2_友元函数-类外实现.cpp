#include <iostream>

// 针对使用到 Person02类型名的行做声明
template<class T1, class T2>
class Person02;

// 针对 第16行做的声明
template <class T1, class T2>
void printPerson2(Person02<T1, T2>& ref);


template<class T1, class T2>
class Person02
{
    // 友元函数，类外实现
    friend void printPerson2<>(Person02<std::string, int>& ref);

    T1 mName;
    T2 mAge;
public:
    Person02(T1 name, T2 age)
    {
        this->mName = name;
        this->mAge = age;
    }
};

template <class T1, class T2>
void printPerson2(Person02<T1, T2>& ref)
{
    std::cout << "繁琐写法: 类外实现 友元函数" << std::endl;
    std::cout << "姓名: " << ref.mName << ", 年龄: " << ref.mAge << std::endl;
}

void test02()
{
    Person02<std::string, int> p1("tom", 12);
    printPerson2(p1);
}

int main2(void)
{
    test02();
    return 0;
}
/*

繁琐写法: 类外实现 友元函数
姓名: tom, 年龄: 12

*/