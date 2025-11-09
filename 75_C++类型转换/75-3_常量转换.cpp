void test03()
{
    // 去除指针const属性
    const int* p = nullptr;
    int* pp = const_cast<int*>(p);

    // 添加指针的const属性
    const int* ppp = const_cast<const int *>(pp);

    // 去除引用const属性
    int num = 1;
    const int& ref1 = num;
    int& ref2 = const_cast<int&>(ref1);
    
    // 添加引用的const属性
    const int& ref3 = const_cast<const int&>(ref2);

    // 不允许去除 普通变量的const属性
    const int a = 2;;
    //int b = const_cast<int>(a);  // error，报错
}

int main3(void)
{
    test03();
    return 0;
}