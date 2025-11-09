#pragma once
#include <iostream>

class MyArr
{
private:
    // 数组的数据区
    int* pAddress;
    // 数组容量
    int mCapacity;
    // 数组元素个数
    int mSize;

public:
    // 构造函数
    MyArr();
    explicit MyArr(int capacity);  // explicit 禁用隐式调用
    MyArr(const MyArr& ref);

    // 析构函数
    ~MyArr();

    // 1. 获取长度
    int getSize();
    // 2. 尾插
    void PushBack(int val);
    // 3. 根据位置设置数据
    void setData(int pos, int val);

    // 4. 根据位置获取数据
    int getData(int pos);

    // 5. 获取数组容量
    int getCapacity();

    // 重载 []运算符
    int& operator[](int idx);
};