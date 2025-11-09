#include <iostream>

class Person
{
    int age;
public:

    void showClass()
    {
        std::cout << "Show Person Class" << std::endl;
    }

    void showAge()
    {
        std::cout << "showAge：" << this->age << std::endl;
    }
};

void test01()
{
    Person* p = NULL;
    p->showClass();  // 正常编译，正常调用
}

void test02()
{
    Person* p = NULL;
    p->showAge();  // 正常编译，运行错误
}

int main(void)
{
    test01();
    test02();

    return 0;
}

/*

Show Person Class
showAge：
D:\cpp_code\bxg\04_C++核心编程\x64\Debug\27_空指针访问成员函数.exe (进程 2320)已退出，代码为 -1073741819。

*/