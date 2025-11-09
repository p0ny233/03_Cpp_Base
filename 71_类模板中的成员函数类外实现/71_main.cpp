#include <iostream>

template<class T1, class T2>
class Person
{
T1 mName;
T2 mAge;

public:

    // 所有 成员函数模板 均类外实现
    Person(T1 name, T2 age);
    void showPerson();
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->mName = name;
    this->mAge = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
    std::cout << "姓名：" << this->mName << "，年龄：" << this->mAge << std::endl; 
}

void test01()
{

    Person<std::string, int> p1("tom", 12);
    p1.showPerson();
}

int main(void)
{
    test01();
    return 0;
}
/*
姓名：tom，年龄：12
*/

