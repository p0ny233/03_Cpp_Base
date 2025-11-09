#include <iostream>

class Person
{
public:
    Person()
    {
        std::cout << "Person 无参构造函数" << std::endl;
    }

    Person(int a) 
    {
        std::cout << "Person 有参构造函数" << std::endl;
    }

    ~Person()
    {
        std::cout << "Person 析构函数" << std::endl;
    }
};

// malloc和new的区别
// 1. malloc是库函数，new是运算符
// 2. malloc不会调用构造函数，new运算符会调用类的构造函数
// 3. malloc返回 void* ，且需要类型转换，new 创建并返回对应类型的对象
void test01()
{
    std::cout << __func__ << std::endl;

    Person *p = new Person;  // 在堆区 创建Person对象
    delete p;  // 释放 堆区的Person对象内存
}

// 注意事项：不要用 void* 接收new出来的对象
void test02()
{
    void* p = new Person;
    delete p;  // 不会调用 析构函数
}

// 利用 new开辟数组
void test03()
{
    std::cout << __func__ << std::endl;

    // 内置的数据类型
    int *pInt = new int[10];
    
    // 在堆区开辟 自定义数据类型的数组，是一定会调用该数据类型的默认构造函数
    Person *pArr = new Person[10];
    // 释放数组
    delete [] pArr;
}

void test04()
{
    std::cout << __func__ << std::endl;
    // 在栈上开辟数组，自定义数据类型可以没有默认构造函数
    Person pArr[10] = {Person(10), Person(20)};
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
    return 0;
}

/*

test01
Person 无参构造函数
Person 析构函数

Person 无参构造函数

test03
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数

test04
Person 有参构造函数
Person 有参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 无参构造函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数
Person 析构函数

*/