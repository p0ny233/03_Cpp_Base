#include <iostream>

class myException
{
public:
    myException()
    {
        std::cout << "myException 构造函数" << std::endl;
    }
    myException(const myException& ref)
    {
        std::cout << "myException 拷贝构造函数" << std::endl;
    }
    ~myException()
    {
        std::cout << "myException 析构函数" << std::endl;
    }
};

void computer()
{
    //throw myException();
    throw& myException();  //  VS IDE不允许 error C2102: “&”要求左值，在 godbolt 带上参数 -fpermissive 运行 
}

void test01()
{
    try
    {
        computer();

    }
    // 1. 调用myException的 拷贝函数
    //catch(myException e)
    //{
    //    std::cout << "catch(myException e)" << std::endl;
    //    /*

    //    myException 构造函数
    //    myException 拷贝构造函数
    //    catch(myException e)
    //    myException 析构函数
    //    myException 析构函数

    //    */
    //}
    // 2. 异常对象 引用 (效率高，推荐)
    catch(myException& e)
    {
        std::cout << "异常对象 引用" << std::endl;
        /*

        myException 构造函数
        异常对象 引用
        myException 析构函数

        */
    }
    // 3. 指针
    catch(myException* e)
    {
        // 异常对象是匿名的，执行创建对象后，立马释放，因此指针指向的是无效区域
        std::cout << "catch(myException* e)" << std::endl;
        /*

        myException 构造函数
        myException 析构函数
        catch(myException* e)

        */
    }
}

int main(void)
{
    test01();
    return 0;
}

/*
    在catch子句中，推荐用 引用类型 接收异常对象
*/