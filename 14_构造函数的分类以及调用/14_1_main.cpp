#include <iostream>
/*
    按照类型分类：普通构造、拷贝构造
*/
class Person
{
    int m_Age;
public:
    Person(){}
    
    Person(int age)
    {
        this->m_Age = age;
    }

    // Person(Person p){} // 不允许这种写法，会造成递归， Person p2(p1)  -> 接着继续调用有参构造Person(Person p)
    // 因此需要用引用，还要避免被修改，因此又加上const
    Person(const Person& ref)   
    {
        if (this == &ref)
            return;
        this->m_Age = ref.m_Age;
    }

    int getAge()
    {
        return m_Age;
    }
};



int main1(void)
{
    Person p1(10);
    Person p2(p1);
    std::cout << "p2的年龄: " << p2.getAge() << std::endl;  // p2的年龄: 10
    return 0;
}