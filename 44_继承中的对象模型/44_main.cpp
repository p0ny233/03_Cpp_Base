#include <iostream>

class BaseA
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Sub1 : public BaseA
{
public:
    int m_D;
};

void test01()
{
    Sub1 s1;
    std::cout << "sizeof(s1): " << sizeof(s1) << std::endl;  // sizeof(s1): 16
}

int main(void)
{
    test01();
    return 0;
}