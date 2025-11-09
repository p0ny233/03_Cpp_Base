// 静态联编

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