#include <iostream>

template<class NAMETYPE, class AGETYPE>
class Person
{
public:
    
    NAMETYPE mName;
    AGETYPE mAge;
    Person(NAMETYPE name, AGETYPE age) : mName(name), mAge(age) {}
};

void test01()
{
    // 规则
    // 1. 类模板无法自动类型推导
    //Person("Tom", 12);
    
    // 2. 类模板只能显式指定
    Person<std::string, int> p1("Tom", 12);
    std::cout << p1.mName << ", " << p1.mAge << std::endl;
    
}

// 3. 类模板参数可以指定默认的数据类型
template <class NAMETYPE, class AGETYPE=int>
class Person02
{
public:
    NAMETYPE mName;
    AGETYPE mAge;
    Person02(NAMETYPE name, AGETYPE age) : mName(name), mAge(age) {}
};

void test02()
{
    Person02<std::string> p1("jack", 14);
    std::cout << p1.mName << ", " << p1.mAge << std::endl;

}


int main(void)
{
    test01();
    test02();

    return 0;
}

/*

Tom, 12
jack, 14

*/