// 1. 在C语言中，struct不允许有函数
//struct Animal
//{
//    int m_a;
//    void func()
//    {
//
//    }
//
//};

// 2. 创建结构体变量时，必须加上 关键字 struct
struct Person
{
    int age;
    char name[64];
};

//int main(void)
//{
//    struct Person p1;
//    p1.age = 12;
//}