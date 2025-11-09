#include <iostream>

class Person
{
public:
    int mAge;
    Person(int age):mAge(age){}
    bool operator==(const Person& p)
    {
        return this->mAge == p.mAge;
    }

    bool operator!=(const Person& p)
    {
        return this->mAge != p.mAge;
    }
};

int main(void)
{
    Person p1(10);
    Person p2(11);

    std::cout << (p1 == p2) << std::endl;  // 0
    std::cout << (p1 != p2) << std::endl;  // 1

    return 0;
}