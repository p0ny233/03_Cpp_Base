// 静态联编，函数调用地址 在 编译期就可以确定，早绑定

#include <iostream>

class Animal
{
public:
    void speak()
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

void test01()
{
    Dog dog;
    doSpeak(dog);
}

int main(void)
{
    test01();
    return 0;
}

/*

动物在说话

*/