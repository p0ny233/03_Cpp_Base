// 调用约定: https://learn.microsoft.com/zh-cn/cpp/cpp/argument-passing-and-naming-conventions?view=msvc-170
// 需要调整为 x86 程序来测试，x64中正常

#include <iostream>

class Animal
{
public:
    virtual void speak()
    {
        std::cout << "Animal Speaking..." << std::endl;
    }

    virtual void eat(int a)
    {
        std::cout << "Animal eating..." << std::endl;
    }
};

class Cat : public Animal 
{
public:
    void speak()
    {
        std::cout << "cat speaking..." << std::endl;
    }

    void eat(int a)
    {
        std::cout << "cat eating..." << ", a = " << a << std::endl;
    }
};

/// <summary>
/// 通过函数指针的方式调用 猫类的 虚函数 speak
/// </summary>
void test01()
{
    Animal *animal = new Cat;
    void** vfptr = *(void***)animal;
    void(__cdecl  *cat_speak_ptr)(void)= (void(__cdecl*)(void))(*vfptr);
    cat_speak_ptr();
}

/// <summary>
/// 当虚函数有了参数后，如何调用
/// 通过函数指针的方式调用 猫类的 虚函数 eat(int)
/// </summary>
void test02()
{
    Animal *animal = new Cat;
    void*** vfptr = *(void****)animal;

    // C和C++ 默认的调用惯例为 __cdecl （堆栈清理是 由 test02来做 ），因此报错
    //void(__cdecl *cat_eat_ptr)(int) = (void(__cdecl*)(int))(*(vfptr + 1));
    //cat_eat_ptr(3);

    // 换成 __stdcall （堆栈清理是 由 被调用方 来做 ） 程序正常
    void(__stdcall * cat_eat_ptr)(int) = (void(__stdcall*)(int))(*(vfptr + 1));
    cat_eat_ptr(10);

    // 简写
    typedef void(__stdcall *FuncType)(int);
    FuncType CatEatPtr = FuncType(*(vfptr + 1));
    CatEatPtr(20);

}
int main(void)
{
    test01();
    std::cout << std::endl;
    test02();
    return 0;
}

/*

cat speaking...

cat eating..., a = 10
cat eating..., a = 20

*/