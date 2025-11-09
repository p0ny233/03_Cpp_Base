/*
    基于 32_数组类封装 实现  []运算符重载
*/

#include "myarr.h"

// 构造函数
MyArr::MyArr()
{
    std::cout << "默认构造函数" << std::endl;
    this->mCapacity = 100;
    this->mSize = 0;
    this->pAddress = new int[this->mCapacity];
}

MyArr::MyArr(int capacity)
{
    std::cout << "有参构造函数" << std::endl;
    this->mSize = 0;
    this->mCapacity = capacity;
    this->pAddress = new int[capacity];
}

MyArr::MyArr(const MyArr& ref)
{
    std::cout << "拷贝构造函数" << std::endl;

    // 进行深拷贝
    if (this == &ref)
        return;

    // 把数据区的数据拷贝一份
    this->mCapacity = ref.mCapacity;
    this->mSize = ref.mSize;
    this->pAddress = new int[this->mCapacity];
    for(int i = 0; i < ref.mSize; i++)
        this->pAddress[i] = ref.pAddress[i];

    // 不需要释放原始数据，否则对象被销毁的时候，会对同一地址进行二次释放
    //delete[] ref.pAddress;
}

// 析构函数
MyArr::~MyArr()
{
    std::cout << __func__ << std::endl;
    if(this->pAddress != nullptr)
        delete[] pAddress;
}


// 1. 获取长度接口
int MyArr::getSize()
{
    return this->mSize;
}


// 2. 尾插
void MyArr::PushBack(int val)
{
    // 1. 容量足够就插入数据
    if(this->mSize < this->mCapacity)
    {
        this->pAddress[this->mSize] = val;
        this->mSize++;
        return;
    }

    // 空间不够，需要动态扩展
    int len = this->mCapacity * 2;
    int* newAddress = new int[len];
    for(int i = 0; i < this->mCapacity; i++)
        newAddress[i] = this->pAddress[i];

    this->pAddress = newAddress;

    // 对原来的堆区释放
    delete[] this->pAddress;
}

// 3. 根据位置设置数据
void MyArr::setData(int pos, int val)
{
    if (pos >= this->mSize)
        return ;  // 位置溢出

    this->pAddress[pos] = val;
}

// 4. 根据位置获取数据
int MyArr::getData(int pos)
{
    if(pos >= this->mSize)
        return -1;  // 位置溢出
    return this->pAddress[pos];
}
// 5. 获取数组容量
int MyArr::getCapacity()
{
    return this->mCapacity;
}


int& MyArr::operator[](int idx)
{
    // idx溢出
    return this->pAddress[idx];
}

void test02()
{
    MyArr myarr1(20);
    for(int i = 0; i < myarr1.getCapacity(); i++)
        myarr1.PushBack(i);

    myarr1[0] = 123;

    for(int i = 0; i < myarr1.getSize(); i++)
    {
        int val = myarr1.getData(i);
        std::cout << val << std::endl;
    }

}


int main(void)
{
    test02();
    return 0;
}

/*
* 
有参构造函数
123
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
~MyArr

*/