#include <iostream>

//////////////////////////  如下没有 继承关系 /////////////////////////////////////////

class Animal_00
{
public:
    virtual void speak()
    {
        std::cout << "动物在说话..." << std::endl;
    }
};

// 没有继承关系，但是内部含有 虚函数，内部依旧会 维护 一个 vfptr 虚函数指针 该指针指向一张虚函数表
void test01()
{
    Animal_00 an;
    std::cout << "sizeof(an): " << sizeof(an) << std::endl;
}

//////////////////////////  如下有 继承关系 /////////////////////////////////////////
class Animal_01
{
public:
    virtual void speak()
    {
        std::cout << "动物在说话..." << std::endl;
    }
};

class Dog : public Animal_01
{
public:
    virtual void speak()
    {
        std::cout << "小狗在说话..." << std::endl;
    }
};

void test02()
{
    Dog dog;
}


int main(void)
{
    test01();
    return 0;
}
/*

sizeof(an): 8

*/