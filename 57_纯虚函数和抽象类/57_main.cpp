#include <iostream>

/*
    抽象类有如下元素：
        1. 属性
        2. 已经实现的函数
        3. 纯虚函数
  
类中只要有一个纯虚函数，这个类就是 抽象类
抽象类不允许 实例化。      
*/
class AbstractDrink
{
public:
    // 煮
    virtual void Boil() = 0;  // 1. 虚函数  2. =0
    // 冲泡
    virtual void Brew() = 0;
    // 倒入
    virtual void PourInto() = 0;
    // 加入辅料
    virtual void AddAdditives() = 0;

    void makeDrink()
    {
        // 煮
        Boil();
        // 冲泡
        Brew();
        // 倒入
        PourInto();
        // 加入辅料
        AddAdditives();
    }
};

class CoffeeDrink : public AbstractDrink
{
public:
    // 煮
    virtual void Boil()
    {
        std::cout << "煮咖啡" << std::endl;
    }

    // 冲泡
    virtual void Brew()
    {
        std::cout << "冲泡咖啡" << std::endl;

    }
    // 倒入
    virtual void PourInto()
    {
        std::cout << "倒入杯中" << std::endl;

    }

    // 加入辅料
    virtual void AddAdditives()
    {
        std::cout << "加入煮咖啡的辅料" << std::endl;
    }
};
class TeaDrink : public AbstractDrink
{
public:

    // 煮
    virtual void Boil()
    {
        std::cout << "煮茶" << std::endl;
    }

    // 冲泡
    virtual void Brew()
    {
        std::cout << "冲泡茶叶" << std::endl;

    }
    // 倒入
    virtual void PourInto()
    {
        std::cout << "倒入杯中" << std::endl;
    }

    // 加入辅料
    virtual void AddAdditives()
    {
        std::cout << "加入柠檬" << std::endl;
    }
};

// 业务函数
void doBussiness(AbstractDrink* ad)
{
    ad->makeDrink();
    delete ad;
}

void test00()
{
    //AbstractDrink ad0;  // error，抽象类不允许被实例化

}

void test01()
{
    AbstractDrink* ad1 = new CoffeeDrink;
    doBussiness(ad1);

    std::cout << std::endl;

    ad1 = new TeaDrink;
    doBussiness(ad1);
}
int main(void)
{
    test01();
    return 0;
}
/*

煮咖啡
冲泡咖啡
倒入杯中
加入煮咖啡的辅料

煮茶
冲泡茶叶
倒入杯中
加入柠檬

*/