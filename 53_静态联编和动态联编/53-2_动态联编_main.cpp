// 动态联编：添加 virtual 关键字修饰父类中的函数，实现 函数晚绑定

#include <iostream>

class Animal
{
public:
    virtual void speak()
    {
        std::cout << "动物在说话" << std::endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        std::cout << "小狗在说话" << std::endl;
    }
};

void doSpeak(Animal& animal)
{
    animal.speak();
}

void test02()
{
    Dog dog;
    doSpeak(dog);
}

int main1(void)
{
    test02();
    return 0;
}