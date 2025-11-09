#include <iostream>

class MyInter
{
    friend std::ostream& operator<<(std::ostream& out, MyInter& inter);

    // 用于后置 ++， a++，因为后置++运算符返回值是一个临时对象，因此必须通过 const 引用接收
    friend std::ostream& operator<<(std::ostream& out, const MyInter& inter);

private:
    int num;

public:
    MyInter() : num(0) {}
    MyInter(int n) : num(n) {}
    // 前置++    ++a
    MyInter& operator++()  // 返回值让其 能够链式调用 ++(++a)
    {
        // 1. 先运算
        this->num++;
        // 2. 后返回结果
        return *this;
    }

    // 后置++    a++
    MyInter operator++(int)  // 使用 int占位，来区分 前置还是后置
    {
        // 1. 先记录对象的初始状态
        MyInter tmp = *this;  // 拷贝构造
        this->num++;
        // 2. 后运算
        return tmp;
    }
};

std::ostream& operator<<(std::ostream& out, MyInter& inter)
{
    out << inter.num;
    return out;
}

// 用于后置 ++， a++， 因为后置++运算符返回值是一个临时对象，因此必须通过 const 引用接收
std::ostream& operator<<(std::ostream& out, const MyInter& inter)
{
    out << inter.num;
    return out;
}

// 测试 ++inter 
void test01()  
{
    std::cout << __func__ << std::endl;
    MyInter inter;
    std::cout << ++(++inter) << std::endl;
    std::cout << inter << std::endl;
}

// 测试 inter++ 
void test02()
{
    std::cout << __func__ << std::endl;
    MyInter inter;  // 0
    //MyInter inter1 = ;
    std::cout << inter++ << std::endl;  // 0
    std::cout << inter << std::endl;    // 1
}

int main(void)
{
    test01();
    test02();
    return 0;
}
/*

test01
2
2
test02
0
1

*/