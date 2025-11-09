#include <iostream>

class Animal
{
public:
    int age;
};

class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};

class SheepTuo : public Tuo, public Sheep
{
public:
    SheepTuo()
    {
        age = 10;
    }
};

void test01()
{
    SheepTuo st;
    std::cout << "st.age: "<< st.age << std::endl;  // st.age: 10
}

// 通过获取到 vbptr 虚基类指针 访问 age
void test02()
{
    SheepTuo st;

    std::cout << "sizeof(st): " << sizeof(st) << std::endl;  // 24个字节
    // 前 16个字节分别是 虚基类指针（vbptr）
    // 后 8 个字节是 类的属性
    

    void** vbPtr1 = *(void***)&st;        // 第一个vbptr
    void** vbPtr2 = *((void***)&st + 1) ; // 第二个vbptr
    
    std::cout << "vbPtr1: " << vbPtr1 << std::endl;
    std::cout << "vbPtr2: " << vbPtr2 << std::endl;

    int offset1 = *(int*)((int*)vbPtr1 + 1);
    int offset2 = *(int*)((int*)vbPtr2 + 1);

    std::cout << "offset1: " << offset1 << std::endl;  // 0x10
    std::cout << "offset2: " << offset2 << std::endl;  // 0x8

    // 通过 vbptr1 访问 Animal的 age成员
    std::cout << "通过 vbptr1 访问 Animal的 age成员: " << ((Animal*)((char*)&st + offset1))->age << std::endl;
    // 那么 offset2 怎么利用???
}

int main(void)
{
    test01();
    std::cout << std::endl;
    test02();
    return 0;
}
/*

st.age: 10

vbPtr1: 00007FF7F189ACC8
vbPtr2: 00007FF7F189ACD8
offset1: 16
offset2: 8
通过 vbptr1 访问 Animal的 age成员: 10

*/