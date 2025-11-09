#include <iostream>

// 0. 出现命名冲突问题
class Person01
{
public:
    int age;

    Person01(int age)
    {
        age = age;
    }
};

void test01()
{
    Person01 p1(18);
    std::cout << "p1的年龄: " << p1.age << std::endl;  // p1的年龄: -858993460
}

// 1. this指针用途1：解决 test01 出现的命名冲突的问题
class Person02
{
public:
    int age;

    Person02(int age)
    {
        this->age = age;
    }
};

void test02()
{
    Person02 p2(18);
    std::cout << "p2的年龄: " << p2.age << std::endl;  // p2的年龄: 18
}

// 2. *this 就是本体
class Person03
{
public:
    int age;
    Person03(int age)
    {
        this->age = age;
    }

    // 以值的方式返回 Person03
    Person03 personAdd(const Person03& ref)  // 调用拷贝构造函数，该函数结束后返回的是新创建的对象，作用不在起始对象
    {
        this->age += ref.age;
        return *this;
    }    
};

void test03()
{
    Person03 p3(10);

    Person03 p4(10);
    p3.personAdd(p4).personAdd(p4).personAdd(p4).personAdd(p4).personAdd(p4).personAdd(p4);
    std::cout << "p3 的年龄: " << p3.age << std::endl;  // p3 的年龄: 20
    // p3的年龄应该是 70，但实际不是，原因是调用 p3.personAdd 函数后，返回是新创建对象，已经与 p3脱离了关系
}

// 解决上述出现的问题
class Person04
{
public:
    int age;
    Person04(int age)
    {
        this->age = age;
    }

    // 返回引用
    Person04& personAdd(const Person04& ref)  // 调用拷贝构造函数，该函数结束后返回的是新创建的对象，作用不在起始对象
    {
        this->age += ref.age;
        return *this;
    }
};

void test04()
{
    Person04 p4(10);
    Person04 p5(10);

    p4.personAdd(p5).personAdd(p5).personAdd(p5).personAdd(p5).personAdd(p5).personAdd(p5);
    
    std::cout << "p4 的年龄: " << p4.age << std::endl;  // p4 的年龄: 70

}



int main(void)
{
    test01();
    test02();
    test03();
    test04();

    return 0;
}

/*

p1的年龄: -858993460
p2的年龄: 18
p3 的年龄: 20
p4 的年龄: 70

*/