#include <iostream>

class Animal
{
public:
    int age;
};

class Sheep : public Animal 
{
public:
    Sheep()
    {
        age = 1;
    }
};

class Tuo : public Animal
{
public:
    Tuo()
    {
        age = 2;
    }
};

class SheepTuo : public Sheep, public Tuo {};

void test01()
{
    SheepTuo st;
    std::cout << "sizeof(st): " << sizeof(st) << std::endl;  // sizeof(s): 8
}

// 菱形继承(钻石继承)下的数据访问
void test02()
{
    SheepTuo st;
    //st.age;   // error, 不明确，产生二义性，两个直接父类都有相同名，不知道访问哪个
    std::cout << st.Sheep::age << std::endl;  // 1
    std::cout << st.Tuo::age << std::endl;    // 2
    
}

int main(void)
{
    test01();
    std::cout << std::endl;
    test02();
    return 0;
}
/*

sizeof(st): 8

1
2

*/