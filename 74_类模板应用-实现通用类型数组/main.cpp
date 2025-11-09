#include "myarr.hpp"
#include "person.hpp"

template <class T>
void printArr(MyArray<T> &arr)
{
    for(int i = 0; i < arr.getSize(); i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

// 1. 测试int数据
void test01()
{
    MyArray<int> myarr01;
    for(int i = 0; i < 20; i++)
    {
        myarr01.pushBack(i+3);
    }
    printArr(myarr01);
}

// 2. 测试char数据
void test02()
{
    MyArray<char> myarr01;
    MyArray<char> myarr02;


    for(int i = 0; i < 20; i++)
    {
        myarr01.pushBack('a'+i);
    }
    printArr(myarr01);
    myarr02 = myarr01;
    myarr02[0] = 'z';
    printArr(myarr02);

}

// 3. 测试double数据
void test03()
{
    MyArray<double> myarr01;
    for(int i = 0; i < 20; i++)
    {
        myarr01.pushBack(3.14 + 0.1 * i);
    }

    MyArray<double> myarr02;
    myarr02 = myarr01;
    
    printArr(myarr01);
    myarr02[0] = 3.333333;
    printArr(myarr02);
}

// 4. 测试Person自定义数据
void test04()
{
    MyArray<Person<std::string, int>> myarr;
    Person<std::string, int> p1("1000", 11);
    Person<std::string, int> p2("1002", 12);
    Person<std::string, int> p3("1001", 11);
    Person<std::string, int> p4("1009", 19);
    Person<std::string, int> p5("1005", 15);
    myarr.pushBack(p1);
    myarr.pushBack(p2);
    myarr.pushBack(p3);
    myarr.pushBack(p4);
    myarr.pushBack(p5);
    printArr(myarr);
    
    std::cout << "myarr1 size: " << myarr.getSize() << std::endl;
    std::cout << "myarr1  Capacity: " << myarr.getCapacity() << std::endl;
    MyArray<Person<std::string, int>> myarr2;
    myarr2 = myarr;
    
    printArr(myarr2);

    std::cout << "myarr2 size: " << myarr2.getSize() << std::endl;
    std::cout << "myarr2 Capacity: " << myarr2.getCapacity() << std::endl;
}

int main(void)
{
    test01();
    test02();
    test03();
    test04();
    return 0;
}
/*

3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t,
z, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t,
3.14, 3.24, 3.34, 3.44, 3.54, 3.64, 3.74, 3.84, 3.94, 4.04, 4.14, 4.24, 4.34, 4.44, 4.54, 4.64, 4.74, 4.84, 4.94, 5.04,
3.33333, 3.24, 3.34, 3.44, 3.54, 3.64, 3.74, 3.84, 3.94, 4.04, 4.14, 4.24, 4.34, 4.44, 4.54, 4.64, 4.74, 4.84, 4.94, 5.04,

姓名: 1000, 年龄：11,
姓名: 1002, 年龄：12,
姓名: 1001, 年龄：11,
姓名: 1009, 年龄：19,
姓名: 1005, 年龄：15,
myarr1 size: 5
myarr1  Capacity: 100

姓名: 1000, 年龄：11,
姓名: 1002, 年龄：12,
姓名: 1001, 年龄：11,
姓名: 1009, 年龄：19,
姓名: 1005, 年龄：15,
myarr2 size: 5
myarr2 Capacity: 100

*/