#include <iostream>

struct Person
{
    int age;
};

// 1. 以指针的方式赋值
void allocSpace01(Person** pp)
{
    // 需要捋清楚：pp指向指针的指针, *pp指针 指向的是person本体，**pp 指向person本体

    // 比较麻烦，因此引出 allocSpace02
    *pp = (Person*)malloc(sizeof(Person));
    if (*pp != NULL)
        (*pp)->age = 11;
}

void test01()
{
    Person * p = NULL;
    allocSpace01(&p);
    std::cout << __func__ << ": " << p->age << std::endl;
}

// 2. 以指针引用方式赋值
void allocSpace02(Person* &ref)  // Person* &ref = p， 操作ref 相当于 操作p
{
    ref = (Person*)malloc(sizeof(Person));
    if (ref != NULL)
        ref->age = 22;
}

void test02()
{
    Person * p = NULL;
    allocSpace02(p);
    std::cout << __func__ << ": " << p->age << std::endl;
}

int main(void)
{
    test01();
    test02();
    return 0;
}
/*

test01: 11
test02: 22

*/