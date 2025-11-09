#pragma once

template <class T1, class T2>
class Person;

// 重载全局 operator<<  ，， 函数实现要紧跟着，不要在 class Person 完整定义的后面
template <class T1, class T2>
std::ostream& operator<<(std::ostream& out, Person<T1, T2>& ref)  // 注意函数名
{
    out << "\n姓名: " << ref.mName << ", 年龄：" << ref.mAge;
    return out;
}


template <class T1, class T2>
class Person
{
    // 友元
    friend std::ostream& operator<<<>(std::ostream& out, Person<T1, T2>& ref);  // 注意函数名

    T1 mName;
    T2 mAge;
public:
    Person(){}  // 必须要 默认构造函数，因为 new Person[] 会调用 Person的默认构造
    Person(T1 name, T2 age);
    Person<T1, T2>& operator=(const Person<T1, T2>& ref);
};

template <class T1, class T2>
Person<T1, T2>& Person<T1, T2>::operator=(const Person<T1, T2>& ref)
{
    this->mName = ref.mName;
    this->mAge = ref.mAge;
    return *this;
}


template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->mName = name;
    this->mAge = age;
}


