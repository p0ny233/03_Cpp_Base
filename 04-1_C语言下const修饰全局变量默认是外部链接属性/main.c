#include <stdio.h>

int main(void)
{
    // 外部链接
    extern const int g_c;
    printf("C语言下的const全局变量外部链接: %d\n", g_c);
    return 0;
}