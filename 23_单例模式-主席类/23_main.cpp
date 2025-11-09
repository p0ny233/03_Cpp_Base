#include <iostream>

class ChairMan
{
private:
    // 1. 将 默认构造和拷贝构造私有化，避免创建多个对象
    ChairMan(){ std::cout << "ChairMan 构造函数" << std::endl; };  // 需要大括号
    ChairMan(const ChairMan &ref){};
    ChairMan(ChairMan &ref){};
 
    // 2. 使用 静态变量存储 唯一实例
    static ChairMan* singleInstance;
public:
    // 3. 提供公共外部接口来获取 唯一实例
    static ChairMan* getInstance()
    {
        return singleInstance;
    }
};

ChairMan* ChairMan::singleInstance = new ChairMan();     // 编译阶段分配内存
// 构造函数私有化了，类外为什么可以调用 ChairMan，是因为该变量在类内进行声明，可以无视权限问题

int main(void)
{
    std::cout << "main 函数" << std::endl;
    ChairMan* c1 = ChairMan::getInstance();
    //new ChairMan;  // 不可访问

    //ChairMan c2(*c1);    // 语法错误，尝试使用拷贝构造函数初始化新的对象
    //ChairMan c2 = *c1;   // 语法错误，尝试使用拷贝构造函数初始化新的对象
    return 0;
}

/*

ChairMan 构造函数
main 函数

*/