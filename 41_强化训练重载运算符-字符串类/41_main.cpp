#include "mystring.h"

void test00()
{
    MyString ms;
    std::cin >> ms;

    std::cout << ms.getLen() << std::endl;
    std::cout << ms;
}

void test01()
{
    std::cout << __func__ << std::endl;
    MyString str = "abc";  // 隐式法，有参构造函数
    MyString str2 = str;   // 隐式法，拷贝构造函数
    
    std::cout << str << std::endl;
    std::cout << "请重新给str赋值: " << std::endl;

    std::cin >> str;
    std::cout << "str新的值为："  << str << ", len: " << str.getLen() << std::endl;
    
    str2 = str;
    std::cout << "str2 = " << str2 << ", len: " << str2.getLen() << std::endl;
}

// 测试内容：有参构造函数、赋值运算符、[]运算符
void test02()
{
    std::cout << __func__ << std::endl;

    MyString str = "abcd";  // 有参构造
    MyString str2 = "aaa";    // 有参构造
    str2 = str;  // 测试 赋值运算符
    
    std::cout << "str2: " << str2 << ", len: " << str2.getLen() << std::endl;
    std::cout << "str2[2]：" << str2[2] << std::endl;
    str2[2] = 'Q';
    std::cout << "修改 str2[2]后的输出: " << str2 << ", len: " << str2.getLen() << std::endl;
}

// 测试内容：有参构造函数、赋值运算符、[]运算符
void test03()
{
    std::cout << __func__ <<std::endl;
    MyString str3 = "abc";
    MyString str4 = "def";
    MyString str5 = str3 + str4;
    std::cout << "str5 = " << str5 << ", len: " << str5.getLen() << std::endl;

    MyString str6 = str3 + ", Hello World";

    std::cout << "str6: " << str6 << ", len: " << str6.getLen() << std::endl;
    std::cout << "str3: " << str3 << ", len: " << str3.getLen() << std::endl;
    std::cout << "str4: " << str4 << ", len: " << str4.getLen() << std::endl;
    std::cout << "str5: " << str5 << ", len: " << str5.getLen() << std::endl;
    std::cout << "str6: " << str6 << ", len: " << str6.getLen() << std::endl;
    
}

// 字符串 比较
void test04()
{
    std::cout << __func__ << std::endl;
    MyString str1 = "abc";
    MyString str2= "def";
    MyString str3 = str1;
    MyString str4;
    str4 = str2;
    if(str3 == str4)
        std::cout << "str3 == str4: " << "True" << std::endl;
    else
    {
        std::cout << "str3: " << str3 << ", len: " << str3.getLen() <<  std::endl;
        std::cout << "str4: " << str4 << ", len: " << str4.getLen() <<  std::endl;
        std::cout << "str3 == str4: " << "False" << std::endl;
        
    }
        
    MyString str5;
    str5 = str5 + "def";
    
    if(str4 == str5)
    {
        std::cout << "str4: " << str4 << ", len: " << str4.getLen() <<  std::endl;
        std::cout << "str5: " << str5 << ", len: " << str5.getLen() <<  std::endl;
        std::cout << "str4 == str5: " << "True" << std::endl;
    }

    MyString str6 = str1 + str2 + str1 + str5 + "helloWorld" + "123123";
    std::cout << "str6: " << str6 << ", len: " << str4.getLen() << std::endl;
}

int main(void)
{
    test01();
    std::cout << std::endl;
    test02();
    std::cout << std::endl;

    test03();
    std::cout << std::endl;

    test04();
    return 0;
}

/*

test01
有参构造函数 MyString::MyString(const char* text)
拷贝构造函数 MyString::MyString(const MyString& ref)
abc
请重新给str赋值:
cin>>自己手动输入的字符串
str新的值为：cin>>自己手动输入的字符串, len: 25
str2 = cin>>自己手动输入的字符串, len: 25
析构构造函数
析构构造函数

test02
有参构造函数 MyString::MyString(const char* text)
有参构造函数 MyString::MyString(const char* text)
str2: abcd, len: 4
str2[2]：c
修改 str2[2]后的输出: abQd, len: 4
析构构造函数
析构构造函数

test03
有参构造函数 MyString::MyString(const char* text)
有参构造函数 MyString::MyString(const char* text)
class MyString __cdecl MyString::operator +(const class MyString &)
有参构造函数 MyString::MyString(const char* text)
str5 = abcdef, len: 6
class MyString __cdecl MyString::operator +(const char *)
有参构造函数 MyString::MyString(const char* text)
str6: abc, Hello World, len: 16
str3: abc, len: 3
str4: def, len: 3
str5: abcdef, len: 6
str6: abc, Hello World, len: 16
析构构造函数
析构构造函数
析构构造函数
析构构造函数

test04
有参构造函数 MyString::MyString(const char* text)
有参构造函数 MyString::MyString(const char* text)
拷贝构造函数 MyString::MyString(const MyString& ref)
无参构造函数 MyString::MyString()
str3: abc, len: 3
str4: def, len: 3
str3 == str4: False
无参构造函数 MyString::MyString()
class MyString __cdecl MyString::operator +(const char *)
有参构造函数 MyString::MyString(const char* text)
析构构造函数
str4: def, len: 3
str5: def, len: 3
str4 == str5: True
class MyString __cdecl MyString::operator +(const class MyString &)
有参构造函数 MyString::MyString(const char* text)
class MyString __cdecl MyString::operator +(const class MyString &)
有参构造函数 MyString::MyString(const char* text)
class MyString __cdecl MyString::operator +(const class MyString &)
有参构造函数 MyString::MyString(const char* text)
class MyString __cdecl MyString::operator +(const char *)
有参构造函数 MyString::MyString(const char* text)
class MyString __cdecl MyString::operator +(const char *)
有参构造函数 MyString::MyString(const char* text)
析构构造函数
析构构造函数
析构构造函数
析构构造函数
str6: abcdefabcdefhelloWorld123123, len: 3
析构构造函数
析构构造函数
析构构造函数
析构构造函数
析构构造函数
析构构造函数

*/