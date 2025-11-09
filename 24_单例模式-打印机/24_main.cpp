#include <iostream>

class Printer
{
public:
    
    // 3. 提供对外接口，获取唯一实例指针
    static Printer* getInstance()
    {
        return singleInstance;
    }

private:
    // 1. 对默认构造、拷贝函数私有化    
    Printer(){ std::cout << "Printer 构造函数" << std::endl; }
    Printer(const Printer& ref){}
    
    // 2. 对唯一实例指针私有化
    static Printer* singleInstance;
};

Printer* Printer::singleInstance = new Printer;  // 编译阶段分配内存

void test01()
{
    Printer* printer = Printer::getInstance();
    
}

int main(void)
{
    std::cout << "main 函数" << std::endl;
    test01();

    return 0;
}

/*

Printer 构造函数
main 函数

*/