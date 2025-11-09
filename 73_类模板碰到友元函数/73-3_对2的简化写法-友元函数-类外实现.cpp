#include <iostream>

// 这里是为了针对 使用到 Person03<T1, T2>数据类型 才提前声明 Person03
template<class T1, class T2>
class Person03;

// 定义和声明同时实现
template <class T1, class T2>
void printPerson3(Person03<T1, T2>& ref)
{
    std::cout << "简化写法: 类外实现 友元函数" << std::endl;
    std::cout << "姓名: " << ref.mName << ", 年龄: " << ref.mAge << std::endl;
}


template<class T1, class T2>
class Person03
{
    // 友元函数，类外实现
    // 函数名后面要加个空的模板参数 <>，说明这是一个函数模板，否则为普通函数
    friend void printPerson3<>(Person03<std::string, int>& ref);

    T1 mName;
    T2 mAge;
public:
    Person03(T1 name, T2 age)
    {
        this->mName = name;
        this->mAge = age;
    }
};

void test03()
{
    Person03<std::string, int> p1("tom", 13);
    printPerson3(p1);
}

int main(void)
{
    test03();
    return 0;
}
/*

简化写法: 类外实现 友元函数
姓名: tom, 年龄: 13

*/