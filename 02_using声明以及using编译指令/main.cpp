#include <iostream>

namespace KingGlory
{
    int sunwukongId = 1;
}

namespace LOL
{
    int sunwukongId = 2;
}

#if 0
// 1. using 声明，结论看 是否成功编译
void test01()
{
    int sunwukongId = 5;

    // 使用using声明
    using KingGlory::sunwukongId;

    // 以上代码报错，当 就近原则(局部变量sunwukong) 与 using声明 同时出现，就会报错，应避免
}
#endif

// 2. using 编译，结论：当using编译指令 与 就近原则 同时出现，则优先使用 就近
void test02()
{
    int sunwukongId = 2222;
    // using编译指令
    using namespace KingGlory;
    
    std::cout << __func__ << ": " << sunwukongId << std::endl;

    // 当 using编译指令有多个时，访问时需要加 作用域前缀
    using namespace KingGlory;
    using namespace LOL;
    std::cout << KingGlory::sunwukongId << std::endl;
    std::cout << LOL::sunwukongId << std::endl;
}

int main(void)
{
    test02();

    return 0;
}

/*

test02: 2222
1
2

*/