// 7. const增强
#include <stdio.h>

// 全局的const变量，数据存储在只读数据区
const int g_var = 100;

void test01()
{
    int* p = &g_var;
    *p = 200;  // 运行阶段出错，修改 只读数据区的数据，

}

// 局部const
void test02()
{
    const int l_var = 300;  // 数据存储在栈上
    //l_var = 444;  // 编译失败，编译阶段报错，由编译器进行 语法检查

    printf("%d\n", l_var);  // 300
    int* ptr = &l_var;
    *ptr = 555;
    printf("%d\n", l_var);  // 555


    // 在 C语言下，const是伪常量
    int arr[l_var];   // 不允许使用const 常量来初始化数组


}


int main(void)
{

    //test01();
    test02();

    
    return 0;
}