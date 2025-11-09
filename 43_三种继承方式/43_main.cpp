#include <iostream>

class BaseA
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_c;
};

/// <summary>
/// 公有继承方式
/// </summary>
class Sub1 : public BaseA
{
public:
    Sub1()
    {
        m_A = 100;  // 在父类中是公有属性，在子类中依旧是公有属性
        m_B = 200;  // 在父类中是保护属性，在子类中依旧是保护属性
        m_C = 300;  // 父类的私有属性，在子类中无法访问
    }
};

void test01()
{
    Sub1 s1;
    std::cout << s1.m_A << std::endl;  // 类外可以访问 公有属性
    //std::cout << s1.m_B << std::endl;  // 类外无法访问 保护属性
    //std::cout << s1.m_C << std::endl;  // 类外无法访问 私有属性
}

/// <summary>
/// 保护继承方式
/// </summary>
class Sub2 : protected BaseA
{
public:
    Sub2()
    {
        m_A = 100;  // 在父类中是公有属性，在子类中是保护属性 (降级)
        m_B = 200;  // 在父类中是保护属性，在子类中是保护属性
        //m_C = 300;  // 父类的私有属性，在子类中无法访问
    }
};
void test02()
{
    Sub2 s2;
    std::cout << s2.m_A << std::endl;    // 类外无法访问 保护属性
    //std::cout << s1.m_B << std::endl;  // 类外无法访问 保护属性
    //std::cout << s1.m_C << std::endl;  // 类外无法访问 私有属性
}

/// <summary>
/// 私有继承方式
/// </summary>
class Sub3 : private BaseA
{
    Sub3()
    {
        m_A = 100;  // 在父类中是公有属性，在子类中是私有属性 (降级)
        m_B = 200;  // 在父类中是保护属性，在子类中是私有属性 (降级)
        m_C = 300;  // 父类的私有属性，在子类中无法访问
    }
};


void test03()
{
    Sub3 s3;
    std::cout << s3.m_A << std::endl;    // 类外无法访问 私有属性
    //std::cout << s1.m_B << std::endl;  // 类外无法访问 私有属性
    //std::cout << s1.m_C << std::endl;  // 类外无法访问 私有属性
}

int main(void)
{
    return 0;
}