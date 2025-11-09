#include <iostream>
/*
    让 GoodGay 作为  Building 的好朋友，可以让 GoodGay访问 Building的私有属性
*/
class Building;  // 声明

class GoodGay
{
private:
    Building* m_building;

public:
    GoodGay();
    
    void visit();
};

class Building
{
    // 使用 frieng 关键字，让 GoodGay 作为 Building 好朋友，可以 GoodGay 可以访问 Building的属性
    friend class GoodGay;

public:
    std::string m_Sitting;

    Building();
private:
    std::string m_BedRoom;
};

Building::Building()
{
    m_Sitting = "客厅";
    m_BedRoom = "卧室";
}

// GoodGay构造函数的实现 要放在 Building 的完整定义之后。原因是内部使用了 Building类型定义的成员变量
GoodGay::GoodGay()
{
    this->m_building = new Building;
}

void GoodGay::visit()
{
    std::cout << "building: " << m_building->m_Sitting << std::endl;
    std::cout << "building: " << m_building->m_BedRoom << std::endl;
}


void test01()
{
    GoodGay gg;

    gg.visit();
}

int main(void)
{
    test01();
    return 0;
}

/*

building: 客厅
building: 卧室

*/