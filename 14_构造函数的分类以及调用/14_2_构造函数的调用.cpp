/*
    构造函数的调用
        1. 括号法调用
        2. 显示法调用
        3. 隐式法调用构造函数 （隐式类型转换法）

*/
#include <iostream>

class Person
{
public:
    Person()  // 无参构造函数
    {
        std::cout << "Person() 无参构造函数, this: " << this << std::endl;
    }
    Person(int age) // 有参构造函数
    {
        std::cout << "Person(int age) 有参构造函数, this: " << this << std::endl;

    }
    Person(const Person& p)  // 拷贝构造函数
    {
        std::cout << "Person(const Person &p) 拷贝构造函数, this: " << this << std::endl;
    }

    ~Person()
    {
        std::cout << "Person的析构函数, this: " << this << std::endl;
    }
};


// 1 括号法调用
void test01()
{
    Person p;  // 无参构造
    Person p1(10);  // 有参构造
    Person p2(p);  // 拷贝构造
}


// 2 显示法调用
void test02()
{
    Person p1 = Person();  // 无参构造

    Person p2 = Person(11); // 有参构造

    Person p3 = Person(p2); // 拷贝构造
    std::cout << __func__ << std::endl;

}

// 匿名对象
void test03()
{
    Person(10);  // 匿名对象，特点：当前行执行完毕，该对象立即被释放
    std::cout << __func__ << std::endl;

}

// 不要用拷贝构造函数 初始化 匿名对象
void test04()
{
    std::cout << __func__ << std::endl;

    Person p1;  // 无参构造函数调用
    // Person(p1);  // 拷贝构造函数 初始化 匿名对象，会导致编译错误，发生重定义
    // Person(p1); 相当于 Person p1; 也就是再次实例化，这是错误的，因为前面已经实例化了 p1，这就导致重定义
}

// 3. 隐式法调用构造函数 （隐式类型转换法）
void test05()
{
    std::cout << __func__ << std::endl;
    // 调用有参构造
    Person p4 = 12;  // 相当于 Person p4 = Person(12);

    // 调用拷贝构造
    Person p5 = p4;  // 相当于 Person p5 = Person(p4);

}

int main(void)
{
    test01();
    std::cout << std::endl;
    test02();
    std::cout << std::endl;

    test03();
    std::cout << std::endl;

    test04();
    std::cout << std::endl;

    test05();
    return 0;
}

/*

Person() 无参构造函数, this: 0000004AF6BFF554
Person(int age) 有参构造函数, this: 0000004AF6BFF574
Person(const Person &p) 拷贝构造函数, this: 0000004AF6BFF594
Person的析构函数, this: 0000004AF6BFF594
Person的析构函数, this: 0000004AF6BFF574
Person的析构函数, this: 0000004AF6BFF554

Person() 无参构造函数, this: 0000004AF6BFF554
Person(int age) 有参构造函数, this: 0000004AF6BFF574
Person(const Person &p) 拷贝构造函数, this: 0000004AF6BFF594
test02
Person的析构函数, this: 0000004AF6BFF594
Person的析构函数, this: 0000004AF6BFF574
Person的析构函数, this: 0000004AF6BFF554

Person(int age) 有参构造函数, this: 0000004AF6BFF654
Person的析构函数, this: 0000004AF6BFF654
test03

test04
Person() 无参构造函数, this: 0000004AF6BFF594
Person的析构函数, this: 0000004AF6BFF594

test05
Person(int age) 有参构造函数, this: 0000004AF6BFF574
Person(const Person &p) 拷贝构造函数, this: 0000004AF6BFF594
Person的析构函数, this: 0000004AF6BFF594
Person的析构函数, this: 0000004AF6BFF574

*/