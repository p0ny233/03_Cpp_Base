/*
    调用的都是父类的无参构造
*/
#include <iostream>

class Other01
{
public:
    Other01()
    {
        std::cout << "Other01 默认构造函数" << std::endl;
    }
    ~Other01()
    {
        std::cout << "~Other01 析构函数调用" << std::endl;
    }
};

class Other02
{
public:
    Other02()
    {
        std::cout << "Other02 默认构造函数" << std::endl;
    }
    ~Other02()
    {
        std::cout << "~Other02 析构函数调用" << std::endl;
    }
};

class BaseA
{
public:
    BaseA()
    {
        std::cout << "BaseA 默认构造函数调用" << std::endl;
    }
    ~BaseA()
    {
        std::cout << "~BaseA 析构函数调用" << std::endl;
    }
};

class Sun1 : public BaseA
{
public:
    Sun1()
    {
        std::cout << "Sun1 默认构造函数调用" << std::endl;
    }
    ~Sun1()
    {
        std::cout << "~Sun1 析构函数调用" << std::endl;
    }
};

class Sun2 : public BaseA
{
public:
    Other01 obj1;
    Sun2()
    {
        std::cout << "Sun2 默认构造函数调用" << std::endl;
    }
    ~Sun2()
    {
        std::cout << "~Sun2 析构函数调用" << std::endl;
    }
};

class Sun3 : public BaseA
{
public:
    Other02 obj2;
    Other01 obj1;
    Sun3()
    {
        std::cout << "Sun3 默认构造函数调用" << std::endl;
    }
    ~Sun3()
    {
        std::cout << "~Sun3 析构函数调用" << std::endl;
    }
};

// 父子类构造顺序， 
// 构造顺序：先构造出父类 再构造子类
// 析构顺序：先析构子类 再析构父类
void test01()
{
    std::cout << __func__ << std::endl;
    Sun1 s1;

/*

test01
BaseA 默认构造函数调用
Sun1 默认构造函数调用
~Sun1 析构函数调用
~BaseA 析构函数调用

*/
}

// 父子类构造顺序， 
// 构造顺序：先构造出父类，然后构造子类成员，再构造子类
// 析构顺序：先析构子类，然后析构子类成员，再析构父类
void test02()
{
    std::cout << __func__ << std::endl;

    Sun2 s2;

/*

test02
BaseA 默认构造函数调用
Other01 默认构造函数
Sun2 默认构造函数调用
~Sun2 析构函数调用
~Other01 析构函数调用
~BaseA 析构函数调用

*/
}

// 父子类构造顺序， 
// 构造顺序：先构造出父类，然后构造子类成员(按照定义的顺序)，再构造子类
// 析构顺序：先析构子类，然后析构子类成员(定义相反顺序)，再析构父类
void test03()
{
    std::cout << __func__ << std::endl;

    Sun3 s3;
/*

test03
BaseA 默认构造函数调用
Other02 默认构造函数
Other01 默认构造函数
Sun3 默认构造函数调用
~Sun3 析构函数调用
~Other01 析构函数调用
~Other02 析构函数调用
~BaseA 析构函数调用

*/
}

int main(void)
{

    test01();
    std::cout << std::endl;
    test02();
    std::cout << std::endl;
    test03();

    return 0;
}

/*

test01
BaseA 默认构造函数调用
Sun1 默认构造函数调用
~Sun1 析构函数调用
~BaseA 析构函数调用

test02
BaseA 默认构造函数调用
Other01 默认构造函数
Sun2 默认构造函数调用
~Sun2 析构函数调用
~Other01 析构函数调用
~BaseA 析构函数调用

test03
BaseA 默认构造函数调用
Other02 默认构造函数
Other01 默认构造函数
Sun3 默认构造函数调用
~Sun3 析构函数调用
~Other01 析构函数调用
~Other02 析构函数调用
~BaseA 析构函数调用

*/