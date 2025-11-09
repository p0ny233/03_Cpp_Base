// 除零异常
#include <iostream>

int myDivision(int a, int b)
{
    if(b == 0)
    {
        //throw -1;   // -1是 int类型，因此抛出的类型为 int
        //throw 'a';  // 'a'是 char，因此抛出的类型为char
        //throw 3.14;  // 抛出double类型

        std::string c = "abc";
        throw c;

    }
    return a / b;
}

void test01()
{
    int a = 10;
    //int b = -10;
    int b = 0;
    try
    {
        std::cout << "ret: " << myDivision(a, b) << std::endl;
    }
    catch(int)
    {
        std::cout << "int 类型异常" << std::endl;
    }
    catch(double)
    {
        std::cout << "double 类型异常" << std::endl;
    }
    catch(char)
    {
        std::cout << "char 类型异常" << std::endl;
    }
    catch(...)
    {
        throw;  // 将异常向上抛出
        std::cout << __func__ << ", 其它 类型异常" << std::endl;
    }
}

int main(void)
{
    try
    {
        test01();
    }
    catch(...)
    {
        std::cout << __func__ << ", 其它 类型异常" << std::endl;

    }
    return 0;
}