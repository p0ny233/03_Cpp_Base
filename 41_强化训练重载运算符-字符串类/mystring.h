#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class MyString;

// 1. 重载 << 
std::ostream& operator<<(std::ostream& out, const MyString& mystirng);
// 2. 重载 >>
std::istream& operator>>(std::iostream& in, MyString& mystring);

class MyString
{
    // 1. 重载 << 
    friend std::ostream& operator<<(std::ostream& out, const MyString& mystirng);
    // 2. 重载 >>
    friend std::istream& operator>>(std::istream& in, MyString& mystring);

private:
    char* pString;
    size_t mSize;

public:
    MyString();

    // 有参构造
    MyString(const char* text);

    // 拷贝构造
    MyString(const MyString& ref);

    ~MyString();

    // 3. 重载 =
    MyString& operator=(const char* str1);
    MyString& operator=(const MyString& str1);

    // 4. 重载 []运算符
    char& operator[](int idx);

    // 5. 重载 +  字符串拼接
    MyString operator+(const char*);
    MyString operator+(const MyString& str);

    // 6. 对比字符串
    bool operator==(const char* str);
    bool operator==(const MyString& str);
    
    // 7. 获取字符串长度
    size_t getLen();
};
