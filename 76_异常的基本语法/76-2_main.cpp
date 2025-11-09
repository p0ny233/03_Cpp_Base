// 抛出 自定义异常类型
#include <iostream>

class myException
{
public:
    myException()
    {
        std::cout << "myException 构造函数" << std::endl;
    }
    myException(const myException& ref)
    {
        std::cout << "myException 拷贝构造函数" << std::endl;
    }
    void printError()
    {
        std::cout << "自定义类型" << std::endl;
    }
};

void myDivision02()
{
    std::cout << __func__ << ", " << myDivision02 << std::endl;
    throw myException();  // 创建了 myException对象，该对象被编译器移动到 异常存储区 而不是在栈中
}

void test02()
{
    std::cout << __func__ << ", " << test02 << std::endl;

    try
    {
        myDivision02();
    }
    catch(myException& e)  // 引用
    {
        std::cout << "异常对象的存储地址：" << &e << std::endl;
        e.printError();
    }
}

int main2(void)
{   
    test02();
    return 0;
}
/*

test02, 00007FF728E61190
myDivision02, 00007FF728E61299
myException 构造函数
异常对象的存储地址：000000D79ECFF4B4
自定义类型


通过地址发现，异常对象的地址不是在栈地址区间，据了解 异常对象是被编译器移动到 异常存储区。
因此由调用者引用异常对象是安全的
*/