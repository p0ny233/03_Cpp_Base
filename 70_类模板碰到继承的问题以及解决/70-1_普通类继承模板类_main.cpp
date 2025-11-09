#include <iostream>

template <class T>
class Animal
{
    T age;
public:
    Animal()
    {
        std::cout << "Animal 构造函数, " << typeid(T).name() << std::endl;
    }
};

// 1. 普通类 继承 模板基类（需指定 基类模板参数 的具体数据类型）
class Dog : public Animal<int>
{

};

void test01()
{
    Dog dog;
}

int main(void)
{
    test01();
    return 0;
}
/*

Animal 构造函数, int

*/