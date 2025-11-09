#include <iostream>

class Person
{
public:
    char *mName;
    int mAge;
    Person(const char* name, int age):mAge(age)
    {
        this->mName = new char[strlen(name) + 1];
        memcpy(this->mName, name, strlen(name) + 1);
    }

    // 重载 赋值运算符
    Person& operator=(const Person& p)
    {
        if (this == &p)
            return *this;
        
        this->mAge = p.mAge;
        if(this->mName)
        {
            delete [] this->mName;
            this->mName = nullptr;
        }

        this->mName = new char[strlen(p.mName) + 1];
        memcpy(this->mName, p.mName, strlen(p.mName) + 1);
        
        return *this;
    }

    ~Person()
    {
        std::cout << "Person 析构函数" << std::endl;
        if(this->mName)
            delete[] this->mName;
    }
};

void test01()
{
    Person p1("Tom", 10);
    Person p2("jerry", 30);
    p2 = p1;
    std::cout << "p2的姓名: " << p2.mName << ", p2的年龄: " << p2.mAge << std::endl;

    Person p3("hello", 11);
    p3 = p2 = p1;
    std::cout << std::endl;
    std::cout << "p1的姓名: " << p1.mName << ", p1的年龄: " << p1.mAge << std::endl;
    std::cout << "p2的姓名: " << p2.mName << ", p2的年龄: " << p2.mAge << std::endl;
    std::cout << "p3的姓名: " << p3.mName << ", p3的年龄: " << p3.mAge << std::endl;

}


int main(void)
{
    test01();

    return 0;
}
/*

p2的姓名: Tom, p2的年龄: 10

p1的姓名: Tom, p1的年龄: 10
p2的姓名: Tom, p2的年龄: 10
p3的姓名: Tom, p3的年龄: 10
Person 析构函数
Person 析构函数
Person 析构函数

*/