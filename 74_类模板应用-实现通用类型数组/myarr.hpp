#include <iostream>

template <class T>
class MyArray
{
    T *pAddr;       // 数据区
    int mCapacity;  // 数组容量
    int mSize;      // 数组元素个数
public:

    // 1. 构造函数
    MyArray();
    MyArray(const MyArray<T>& ref);    
    ~MyArray();

    // 2. 运算符相关
    T& operator[](int idx);
    MyArray<T>& operator=(const MyArray<T>& ref);
    
    // 公共接口相关
    int getSize();      // 获取元素个数
    int getCapacity();  // 获取数组容量大小
    void pushBack(T val);// 尾插元素
    void clear();
};

// 1. 默认构造函数
template <class T>
MyArray<T>::MyArray()
{
    this->mCapacity = 100;
    this->pAddr = new T[this->mCapacity];  // T 若代表 Person自定义数据类型，new[] 一定会调用 Person的默认构造函数
    this->mSize = 0;
}

// 拷贝构造
template <class T>
MyArray<T>::MyArray(const MyArray<T>& ref)
{
    this->mCapacity = ref.mCapacity;
    this->pAddr = new T[this->mCapacity];
    this->mSize = ref.mSize;    
    memcpy(this->pAddr, ref.pAddr, sizeof(T) * this->mSize);
}

template <class T>
MyArray<T>::~MyArray()
{
    if(this->pAddr != nullptr)
    {
        delete[] this->pAddr;
        this->pAddr = nullptr;
    }
}

// 2. 运算符相关
template <class T>
T& MyArray<T>::operator[](int idx)
{
    return this->pAddr[idx];
}

template <class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& ref)
{
    // 1. 将原始内存释放
    if(this->pAddr != nullptr)
        delete[] this->pAddr;
    this->mCapacity = ref.mCapacity;
    this->mSize = ref.mSize;
    this->pAddr = new T[this->mCapacity];

    // 2. 将数据拷贝
    //memcpy(this->pAddr, ref.pAddr, sizeof(T) * this->mSize);  
    // 注意这里不能使用 memcpy， 拷贝了Person类型的mName地址，后面会出现二次释放

    for(int i = 0; i < this->mSize; i++)
    {
        this->pAddr[i] = ref.pAddr[i];
    }
    // 返回引用还是 新的副本???
    return *this;  // 应该是 引用??
}

// 公共接口相关
// 获取元素个数
template <class T>
int MyArray<T>::getSize()
{
    return this->mSize;
}

// 获取数组容量大小
template <class T>
int MyArray<T>::getCapacity()
{
    return this->mCapacity;
}

// 尾插元素
template <class T>
void MyArray<T>::pushBack(T val)
{
    this->pAddr[this->mSize] = val;
    this->mSize++;
}

// 清空元素
template <class T>
void MyArray<T>::clear()
{
    if (this->pAddr != nullptr)
        delete[] this->pAddr;
    this->mCapacity = 0;
    this->mSize= 0;
    this->pAddr = nullptr;
    
}