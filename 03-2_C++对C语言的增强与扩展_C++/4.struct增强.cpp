// 1. 在C++中，struct 允许有函数
struct Animal
{
    int m_a;
    void func()
    {

    }

};

// 2. 创建结构体变量时，可以忽略 关键字 struct
struct Person
{
    int age;
    char name[64];
};

int main4(void)
{
    Person p1;
    p1.age = 12;
    return 0;
}