#include <iostream>

template <class T1, class T2>
class Person02
{
    T1 mName;
    T2 mAge;

public:
    Person02();
    void showPerson();
};

template <class T1, class T2>
Person02<T1, T2>::Person02()
{
    std::cout << "Person02 构造函数" << std::endl;
}

template <class T1, class T2>
void Person02<T1, T2>::showPerson()
{
    std::cout << "Person02 showPerson" << std::endl;
}