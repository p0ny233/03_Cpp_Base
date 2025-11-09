// 动态联编，函数调用地址 在 运行时才能确定，晚绑定

/*


产生多态的条件：
1. 先有继承关系
2. 父类中有虚函数，子类重写父类中的虚函数
3. 父类的指针或引用，可以指向子类的对象

*/
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

小狗在说话

*/