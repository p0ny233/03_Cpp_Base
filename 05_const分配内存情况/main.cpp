/*

    1. 对const变量取地址
    2. 使用普通变量，初始化const变量
    3. 对于自定义类型(无法验证，更新了)
*/
#include <iostream>
#include <string>
// 1. 对const变量取地址，会在栈中开辟内存
void test01()
{
    const int a = 123;
    int* pa = (int*)&a;
    
}

// 2. 使用普通变量，初始化const变量
void test02()
{
    int b = 11;      // 普通变量
    const int c = b; // 初始化const变量，如果赋值号右边是字面值，再把const符号加到符号表

    int* pc = (int*)&c;
    *pc = 1000;
    std::cout << "c = " << c << std::endl;  // 1000
}
struct Person
{
    std::string mName;
    int mAge;
};
// 3. 对于自定义类型
void test03()
{
    const Person p;  // 编译时 提示 必须初始化 const 对象， error C2737: “p”: 必须初始化 const 对象
    //p.mName = name;  // 会产生两个问题，1. 类型不匹配，2. const修饰的对象不可直接修改
    Person * pp = (Person*)&p;
    pp->mName = "Tom";
    pp->mAge = 12;

    std::cout << "姓名：" << p.mName << "年龄：" << p.mAge << std::endl;

}

int main(void)
{
    test02();
    test03();
    return 0;
}