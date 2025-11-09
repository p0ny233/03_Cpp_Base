/*
    拷贝构造函数调用时机
        1. 用已经创建好的对象 初始化另一个对象    
        2. 以值的方式传递类对象
        3. 以值的方式返回类对象
*/
#include <iostream>

class Person
{
public:
    int mAge;
    Person()
    {
        mAge = 0;
        std::cout << "Person 默认构造函数" << std::endl;
    }  // 默认构造
    Person(int age)
    {
        this->mAge = age;
        std::cout << "Person 有参构造函数" << std::endl;
    }
    Person(const Person& ref) 
    {
        this->mAge = ref.mAge;
        std::cout << "Person 拷贝构造函数" << std::endl;
    }
    ~Person()
    {
        std::cout << "Person 析构函数" << std::endl;
    }

    
};

// 1. 用已经创建好的对象 初始化另一个对象
void test01()
{
    std::cout << __func__ << std::endl;
    Person p1(18);
    Person p2 = p1;  // 等价 Person p2(p1); 调用拷贝构造函数
    std::cout << "p2的年龄: " << p2.mAge << std::endl;

}

// 2. 以值的方式传递类对象
void doWork(Person p)  // 调用 拷贝构造函数
{
    std::cout << "doWork中的p的年龄: " << p.mAge << std::endl;
}
    
void test02()
{
    std::cout << __func__ << std::endl;
    Person p(19);
    doWork(p);
}

// 3. 以值的方式返回类对象  注意：现代编译器可能会进行返回值优化（RVO/NRVO），省略不必要的拷贝构造调用
// 因此看不到 拷贝构造函数的调用
Person doWork2()
{
    Person p(20);
    std::cout << __func__ << " - p的地址: " << &p << std::endl;
    return p;
}

void test03()
{
    std::cout << __func__ << std::endl;
    //doWork2();  // 相当于匿名对象
    Person p3 = doWork2();
    std::cout << "p3的年龄: " << p3.mAge << ", p3的地址：" << &p3 << std::endl;

}


int main(void)
{
    test01();
    std::cout << std::endl;
    test02();
    std::cout << std::endl;
    test03();
    return 0;
}
/*

test01
Person 有参构造函数
Person 拷贝构造函数
p2的年龄: 18
Person 析构函数
Person 析构函数

test02
Person 有参构造函数
Person 拷贝构造函数
doWork中的p的年龄: 19
Person 析构函数
Person 析构函数

test03
Person 有参构造函数
doWork2 - p的地址: 000000564BD9FA24
p3的年龄: 20, p3的地址：000000564BD9FA24
Person 析构函数

*/