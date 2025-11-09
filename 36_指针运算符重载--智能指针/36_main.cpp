#include <iostream>

class Person
{
private:
    int mAge;
public:
    Person(int age): mAge(age)
    {
        std::cout << "Person 有参构造函数调用" << std::endl;
    }
    void showAge()
    {
        std::cout << "age: " << mAge << std::endl;
    }

    ~Person()
    {
        std::cout << "Person 析构函数调用" << std::endl;
    }

};

class SmartPoint
{
private:
    Person* mPerson;

public:
    SmartPoint(Person* person)
    {
        this->mPerson = person;
    }

    // 1. 重载 -> 运算符
    Person* operator->()
    {
        return this->mPerson;
    }
    // 2. 重载 * 运算符
    Person& operator*()
    {
        return *this->mPerson;
    }

    ~SmartPoint()
    {
        if(this->mPerson)
        {
            delete this->mPerson;
            this->mPerson = nullptr;
        }
    }
};

void test01()
{
    SmartPoint sp(new Person(18));
    // 1. 使用 ->运算符
    sp->showAge();  // 本质写法：sp->->showAge(); 编译器优化为：sp->showAge();
    // 2. 使用 * 运算符
    (*sp).showAge();
}

int main(void)
{
    test01();
    return 0;
}

/*

Person 有参构造函数调用
age: 18
age: 18
Person 析构函数调用

*/