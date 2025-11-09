#include <iostream>

class AbstractCalculate
{
public:
    int m_A;
    int m_B;

    virtual int getResult() 
    {
        return 0;
    }
};

// 加法类
class AddCalculate : public AbstractCalculate
{
public:
    int getResult()
    {
        return m_A + m_B;
    }
};

// 减法类
class SubCalculate : public AbstractCalculate
{
public:
    int getResult()
    {
        return m_A - m_B;
    }
};

// 乘法类
class MulCalculate : public AbstractCalculate
{
public:
    int getResult()
    {
        return m_A * m_B;
    }
};

void test01()
{
    std::cout << "加法类" << std::endl;
    AbstractCalculate * obj = new AddCalculate;
    obj->m_A = 10;
    obj->m_B = 20;
    std::cout << "result: " << obj->getResult() << std::endl << std::endl;
    delete obj;

    std::cout << "减法类" << std::endl;
    obj = new SubCalculate;
    obj->m_A = 101;
    obj->m_B = 32;
    std::cout << "result: " << obj->getResult() << std::endl << std::endl;
    delete obj;

    std::cout << "乘法类" << std::endl;
    obj = new MulCalculate;
    obj->m_A = 3;
    obj->m_B = 2;
    std::cout << "result: " << obj->getResult() << std::endl << std::endl;
    delete obj;
}

int main(void)
{
    test01();
    return 0;
}
/*

加法类
result: 30

减法类
result: 69

乘法类
result: 6

*/