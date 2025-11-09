#include <iostream>

template <class T1, class T2>
class Person
{
    T1 mName;
    T2 mAge;
public:
    Person(T1 name, T2 age) : mName(name), mAge(age) {}
    void showPerson()
    {
        std::cout << this->mName << ", " << this->mAge << std::endl;
    }
};

// 2. 参数模板化
template <class T1, class T2>
void doWork02(Person<T1, T2>& ref)
{
    std::cout << "T1的数据类型: " << typeid(T1).name() << std::endl;
    std::cout << "T2的数据类型: " << typeid(T1).name() << std::endl;
    ref.showPerson();
}

void test02()
{
    std::cout << __func__ << " 参数模板化" << std::endl;
    Person<std::string, int> p1("jack02", 12);
    doWork02(p1);
}
// 2. 整个类 模板化
template <class T>
void doWork03(T& ref)
{
    std::cout << "T的数据类型: " << typeid(T).name() << std::endl;
    ref.showPerson();
}

void test03()
{
    std::cout << __func__ << " 整个类模板化" << std::endl;
    Person<std::string, int> p1("jack03", 13);
    doWork03(p1);
}

int main(void)
{
    test02();
    std::cout << std::endl;

    test03();
    std::cout << std::endl;

    return 0;
}


/*

test02 参数模板化
T1的数据类型: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
T2的数据类型: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
jack02, 12

test03 整个类模板化
T的数据类型: class Person<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int>
jack03, 13

*/