//仅当成员函数被调用或使用时，编译器才为当前类模板的类型参数生成对应的函数实例；
#include <iostream>

class Person01
{
public:
    
    Person01()
    {
        std::cout << "Person 构造函数" << std::endl;
    }
    ~Person01()
    {
        std::cout << "Person 析构函数" << std::endl;
    }

    void showPerson01()
    {
        std::cout << "showPerson01" << std::endl;
    }
};

class Person02
{
public:
    void showPerson02()
    {
        std::cout << "showPerson02" << std::endl;
    }
};

template <class T>
class MyClass
{
    T obj;
public:

    MyClass()
    {
        std::cout << "MyClass 构造" << std::endl;
    }

    ~MyClass()
    {
        std::cout << "MyClass 析构" << std::endl;
    }

    void func1()
    {
        obj.showPerson01();
    }
    void func2()
    {
        obj.showPerson02();
    }
};

void test01()
{
    MyClass<Person01> clz;  // 实例化 Person01对象
    clz.func1();
    //clz.func2();  // 对这行进行注释，然后编译正常，对这行放开，编译报错，说明只有调用 func2的时候，才会编译func2
    // 类模板中没调用到成员函数没有进行参与编译。
    // 可以说明 类模板中的成员函数被调用时参与编译
}

int main(void)
{
    test01();
    return 0;
}
/*

Person 构造函数
MyClass 构造
showPerson01
MyClass 析构
Person 析构函数

*/