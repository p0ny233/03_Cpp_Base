#include <iostream>

// 父类中的 func函数 进行 重载
class BaseA
{
public:
    void func()
    {
        std::cout << "BaseA::func() 调用" << std::endl; 
    }
    void func(int a)
    {
        std::cout << "BaseA::func(int a) 调用" << std::endl; 
    }
};

class Sun01: public BaseA
{
public:
    // 子类重写 父类的func函数
    void func()
    {
        std::cout << "Sun01::func() 调用" << std::endl;
    }
};

void test01()
{
    Sun01 s1;

    //s1.func(100);  
// 理论上 可以访问 父类的 func，但由于子类重写父类func，导致子类屏蔽父类中所有重载版本的func函数
// 因此需要显式调用父类的重载版本函数，如下：
    s1.BaseA::func(100);
}

int main(void)
{
    test01();
    return 0;
}

/*

BaseA::func(int a) 调用

*/