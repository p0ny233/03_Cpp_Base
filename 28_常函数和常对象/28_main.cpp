#include <iostream>


// 常函数
class Person
{
public:
    int m_Age;
    mutable int m_Bge;  // mutable 关键字，让该属性可以在常函数中可被修改
    Person(int age)
    {
        this->m_Age = age;
    }

    void showAge() const  // 加const，目的只让 showAge函数对 成员变量 只读，不可写
    {
        //this->m_Age = 11;  // 语法错误
    
        this->m_Bge = 12;  // 如果想在常函数中修改 成员变量，那么就将得使用 mutable关键字修饰这个变量


        std::cout << "person age: " << this->m_Age << std::endl;
        std::cout << "person m_Bge: " << this->m_Bge << std::endl;
    }
};

void test01()
{
    Person p(10);
    p.showAge();
}


// 常对象
class Person02
{
public:
    int mAge;
    
    Person02(int age) {mAge = age;}
    //void func(){}  // 编译错误
    void showAge() const
    {
        std::cout << "年龄: " << this->mAge << std::endl;
    }
};

void test02()
{
    const Person02 p2(10);

    //p2.mAge = 12;  // 常对象不许修改成员属性

    //p2.func();  // 编译错误，常对象只能调用常函数
    p2.showAge();


}

int main(void)
{

    test01();
    test02();
    return 0;
}

/*

person age: 10
person m_Bge: 12
年龄: 10

*/