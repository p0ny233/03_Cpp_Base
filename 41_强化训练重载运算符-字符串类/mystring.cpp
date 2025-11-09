#include "mystring.h"

// 1. 重载 << 
std::ostream& operator<<(std::ostream& out, const MyString& mystirng)
{
    out << mystirng.pString;
    return out;
}

//// 2. 重载 >> （有问题）
//std::istream& operator>>(std::istream& in, MyString& mystring)
//{
//    // 将字符串写入到 mystring.pString？那 mystring内部的大小该设置多少
//    in >> mystring.pString;  // 如果 mystring.pString 的堆区 小于 输入的字符串的大小，那么怎么解决
//    size_t len = strlen(mystring.pString);
//    mystring.mSize = len;
//    return in;
//}

// 2. 重载 >> 右移运算符
std::istream& operator>>(std::istream& in, MyString& mystring)
{
    // 0. 创建临时缓冲
    char buff[1024];
    // 1. 先释放 原有的堆区
    if(mystring.pString != nullptr)
        delete[] mystring.pString;
    // 2. 将输入字符串写入缓冲
    std::cin >> buff;
    // 3. 再计算需要多大的堆区
    size_t len = strlen(buff);
    mystring.pString = new char[len+1];
    mystring.mSize = len;
    memcpy(mystring.pString, buff, mystring.mSize+1);
    return in;
}

MyString::MyString()
{
    std::cout << "无参构造函数 MyString::MyString()" << std::endl;
    this->pString = nullptr;
    this->mSize = 0;
}

// 有参构造
MyString::MyString(const char* text)
{
    std::cout << "有参构造函数 MyString::MyString(const char* text)" << std::endl;

    this->pString = new char[strlen(text) + 1];
    memcpy(this->pString, text, strlen(text) + 1);
    this->mSize = strlen(text);
}

// 拷贝构造
MyString::MyString(const MyString& ref)
{
    std::cout << "拷贝构造函数 MyString::MyString(const MyString& ref)" << std::endl;

    this->pString = new char[strlen(ref.pString) + 1];
    memcpy(this->pString, ref.pString, strlen(ref.pString) + 1);
    this->mSize = ref.mSize;
}

MyString::~MyString()
{
    std::cout << "析构构造函数" << std::endl;

    if(this->pString)
        delete[] this->pString;
}

// 3. 重载 =
MyString& MyString::operator=(const char* str1)
{
    if(this->pString != nullptr)
        delete [] this->pString;

    this->pString = new char[strlen(str1) + 1];
    memcpy(this->pString, str1, strlen(str1) + 1);
    this->mSize = strlen(str1);
    return *this;
}

MyString& MyString::operator=(const MyString& str1)
{
    if(this->pString != nullptr)
        delete[] this->pString;

    this->pString = new char[strlen(str1.pString) + 1];
    memcpy(this->pString, str1.pString, strlen(str1.pString) + 1);
    this->mSize = strlen(str1.pString);

    return *this;
}

// 4. 重载 []运算符
char& MyString::operator[](int idx)
{
    return this->pString[idx];
}

// 5. 重载 +  字符串拼接
MyString MyString::operator+(const char* text)
{
    std::cout << __FUNCSIG__ << std::endl;  // 输出完整的函数签名
    // class MyString __cdecl MyString::operator +(const char *)
    size_t len = 0;
    if(this->pString)
        len = strlen(this->pString) + strlen(text) + 1;
    else
        len = strlen(text) + 1;

    char* newString = new char[len];
    memset(newString, 0, len);
    if(this->pString)
        strcpy(newString, this->pString);
    strcat(newString, text);
    MyString tmp = newString;  // 有参构造 MyString(const char* text);
    memcpy(tmp.pString, newString, len);
    tmp.mSize = len - 1;
    delete[] newString;
    return tmp;
}

MyString MyString::operator+(const MyString& str)
{
    std::cout << __FUNCSIG__  << std::endl;  // 输出完整的函数签名
    size_t len = strlen(this->pString) + strlen(str.pString) + 1;
    char* buff = new char [len];
    strcpy(buff, this->pString);
    strcat(buff, str.pString);

    MyString tmp = buff;  // 调用 有参构造函数 MyString::MyString(const char* text)
    tmp.mSize = len-1;

    delete[] buff;
    
    return tmp;
}

// 6. 对比字符串
bool MyString::operator==(const MyString& str)
{
    return strcmp(this->pString, str.pString) == 0;
}

bool MyString::operator==(const char* str)
{
    return strcmp(this->pString, str) == 0;
}


// 7. 获取字符串长度
size_t MyString::getLen()
{
    return this->mSize;
}