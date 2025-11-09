#include <iostream>

template <class T1, class T2>
class Person
{
    T1 mName;
    T2 mAge;
public:
    Person(T1 name, T2 age) : mName(name), mAge(age){}
    void showPerson()
    {
        std::cout << this->mName << ", " << this->mAge << std::endl;
    }
};

// 1. 指定类型传入
void doWork01(Person<std::string, int> &ref)
{
    ref.showPerson();
}

void test01()
{
    std::cout << __func__ << " 指定类型传入" << std::endl;
    Person<std::string, int> p1("jack01", 11);
    doWork01(p1);
}

// 2. 参数模板化
template <class T1, class T2>
void doWork02(Person<T1, T2> &ref)
{
    ref.showPerson();
}

void test02()
{
    std::cout << __func__ << " 参数模板化" << std::endl;
    Person<std::string, int> p1("jack02", 12);
    doWork02(p1);
}
// 3. 整个类 模板化
template <class T>
void doWork03(T &ref)
{
    ref.showPerson();
}

void test03()
{
    std::cout << __func__ << " 整个类模板化" << std::endl;
    Person<std::string, int> p1("jack03", 13);
    doWork03(p1);
}

int main(void)
{
    test01();
    std::cout << std::endl;

    test02();
    std::cout << std::endl;

    test03();
    std::cout << std::endl;

    return 0;
}
/*

test01 指定类型传入
jack01, 11

test02 参数模板化
jack02, 12

test03 整个类模板化
jack03, 13

*/