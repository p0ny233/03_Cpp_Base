#include <iostream>

template <class T>
class Animal02
{
    T age;
public:
    Animal02()
    {
        std::cout << "Animal02 构造函数, " << typeid(T).name() << std::endl;
    }
};

// 2. 模板类继承模板基类（可传递模板参数）
template <class T1, class T2>
class Cat : public Animal02<T2>
{
public:
    Cat()
    {
        std::cout << "Cat 构造函数"
            << ", T1的数据类型: "
            << typeid(T1).name()
            << "\nT2的数据类型 : "
            << typeid(T2).name()
            << std::endl;
    }
};

void test02()
{
    Cat<std::string, int> cat;
}
int main2(void)
{
    test02();
    return 0;
}
/*

Animal02 构造函数, int
Cat 构造函数, T1的数据类型: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
T2的数据类型 : int

*/